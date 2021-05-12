#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <map>
#include <QDir>
#include "FeatureExtraction.hpp"
using namespace std;
using namespace cv;
using namespace ml;

class ORCDetect {
private:
    Mat traindatas;
    Mat trainlabels;
    vector<vector<float>> feature_vec;
public:
    ORCDetect() = default;
    void readImageAndBinary(const string& img_path) {
        cout << "start read images" << endl;
        QDir dir(QString::fromStdString(img_path));
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            string img_name = fileInfo.completeBaseName().toStdString();
            string img_path = fileInfo.absoluteFilePath().toLocal8Bit().data();
            Mat img_mat = imread(img_path);
            Mat dst;
            threshold(img_mat, dst, 110, 255, THRESH_BINARY);
            string wpath = fileInfo.absolutePath().toStdString() + "/" + img_name + "_bin.png";
            cout << "wpath : " << wpath << endl;
            imwrite(wpath, dst);
        }
    }
    Mat processImage(const string& path) {
        Mat img_mat = imread(path, 0);
        constexpr size_t fea_size = 30;
        //Mat feature_img = img_mat.rowRange(30,121);
        //vector<float> pixelFeature = charterFeatureExtra(feature_img, 18);
        vector<float> fea_data;
        FeatureExtraction::fitFun(img_mat, fea_data);
        auto padding_size = fea_size - fea_data.size();
        for(size_t i = 0; i < padding_size; ++i) {
            fea_data.push_back(-1);
        }
        Mat mat = Mat(fea_data, true);
        Mat dst = mat.reshape(1, 1);
        return dst;
    }
    vector<float> processImage3(const string& path) {
        Mat img_mat = imread(path, 0);
        constexpr size_t fea_size = 30;
        //Mat feature_img = img_mat.rowRange(30,121);
        //vector<float> pixelFeature = charterFeatureExtra(feature_img, 18);
        vector<float> fea_data;
        FeatureExtraction::fitFun(img_mat, fea_data);
        auto padding_size = fea_size - fea_data.size();
        for(size_t i = 0; i < padding_size; ++i) {
            fea_data.push_back(-1);
        }

        return fea_data;

    }
    vector<float> processImage2(const string& path, int label) {
        Mat img_mat = imread(path, 0);
        constexpr size_t fea_size = 30;
        //Mat feature_img = img_mat.rowRange(30,121);
        //vector<float> pixelFeature = charterFeatureExtra(feature_img, 18);
        vector<float> fea_data;
        FeatureExtraction::fitFun(img_mat, fea_data);
        auto padding_size = fea_size - fea_data.size();
        for(size_t i = 0; i < padding_size; ++i) {
            fea_data.push_back(-1);
        }
        fea_data.push_back(label);
        return fea_data;
    }
    void processTrainImages2(const string& img_path, int label) {

        QDir dir(QString::fromStdString(img_path));
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();

        Mat trainingData;
        Mat labels;
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            string img_name = fileInfo.completeBaseName().toStdString();
            string img_path = fileInfo.absoluteFilePath().toLocal8Bit().data();
            feature_vec.push_back(processImage2(img_path,label))
            //traindatas.push_back(processImage(img_path));
            //trainlabels.push_back(label);
        }
    }
    void imgPreProcessAndTrain2() {
        string path = "d:/image/train/";
        vector<char> labels{'a','A','E','F','G','I','J','K'};
        for(size_t i = 0; i < labels.size();++i) {
            auto temp = path;
            temp.push_back(labels[i]);
            processTrainImages2(temp, static_cast<int>(labels[i]));
        }

        string path1 = "d:/image/pre/k04_s.png";
        vector<float> feature_mat = processImage3(path1);
        float min = 100;
        int min_index = 0;
        for(size_t i = 0; i < feature_vec.size(); ++i) {
            auto v = feature_vec[i];
            v.pop_back();
            auto res = compareHist(v, feature_mat, HISTCMP_BHATTACHARYYA);
            if(res < min) {
                min = res;
                min_index = i;
            }
        }
        cout << "predict char is " << feature_vec[min_index].back();


    }
    void predictChar2() {

    }
    void processTrainImages(const string& img_path, int label) {
        cout << "start read images" << endl;
        QDir dir(QString::fromStdString(img_path));
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();
        cout << "list size "  << list.size() << endl;
        Mat trainingData;
        Mat labels;
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            string img_name = fileInfo.completeBaseName().toStdString();
            string img_path = fileInfo.absoluteFilePath().toLocal8Bit().data();
            cout << "image_path" << img_path << endl;
            traindatas.push_back(processImage(img_path));
            trainlabels.push_back(label);
        }
    }
    vector<float> charterFeatureExtra(const Mat& img, int row_step) {
        auto filter = Mat::ones(5,5,CV_8UC1);
        auto w = filter.size().width;
        auto h = filter.size().height;
        auto filter_num = w*h;
        constexpr int col_step = 3;
        constexpr int row_count = 5;
        vector<float> pixelFeature;

        for(int i = 0; i < row_count; ++i) {                         //取5份
            Range row_range(0 + i*row_step, 5 + i*row_step); //row_step为18
            for(int j = 0; j <= 17; ++j) {
                Range col_range(0 + j*(col_step+5), 5 + j*(col_step+5));
                auto subMat = img(row_range, col_range);
                auto sum = subMat.dot(filter);              
                auto value = sum / filter_num;
                pixelFeature.push_back(value);
            }
        }
        return pixelFeature;
    }

    Ptr<SVM> SVMTrain(cv::Mat& traindata, cv::Mat& clas) {
        Ptr<SVM> SVM_params = SVM::create();
        SVM_params->setType(SVM::C_SVC);//C_SVC用于分类，C_SVR用于回归
        SVM_params->setKernel(SVM::LINEAR);  //LINEAR线性核函数。SIGMOID为高斯核函数
        SVM_params->setDegree(0);//核函数中的参数degree,针对多项式核函数;
        SVM_params->setGamma(1);//核函数中的参数gamma,针对多项式/RBF/SIGMOID核函数;
        SVM_params->setCoef0(0);//核函数中的参数,针对多项式/SIGMOID核函数；
        SVM_params->setC(1);//SVM最优问题参数，设置C-SVC，EPS_SVR和NU_SVR的参数；
        SVM_params->setNu(0);//SVM最优问题参数，设置NU_SVC， ONE_CLASS 和NU_SVR的参数；
        SVM_params->setP(0);//SVM最优问题参数，设置EPS_SVR 中损失函数p的值.
        //结束条件，即训练1000次或者误差小于0.01结束
        SVM_params->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 1000, 0.01));
        cout << "data type is " << traindata.type() << endl;
        cout << "label type is " << clas.type() << endl;
        //训练数据和标签的结合
        Ptr<TrainData> tData = TrainData::create(traindata, ROW_SAMPLE, clas);
        // 训练分类器
        SVM_params->train(tData);//训练
        //保存模型
        SVM_params->save("d:/image/svm.xml");
        return SVM_params;

    }
    Ptr<SVM> imgPreProcessAndTrain() {
        string path = "d:/image/train/";
        vector<char> labels{'a','A','E','F','G','I','J','K'};
        for(size_t i = 0; i < labels.size();++i) {
            auto temp = path;
            temp.push_back(labels[i]);
            processTrainImages(temp, static_cast<int>(labels[i]));
        }

        Mat trainingData;
        Mat traininglabels;
        Mat(traindatas).copyTo(trainingData);//复制
        trainingData.convertTo(trainingData, CV_32F);//更改图片数据的类型
        Mat(trainlabels).copyTo(traininglabels);//复制
        Ptr<SVM> para = SVMTrain(trainingData, trainlabels);
        return para;
    }
    void predictChar() {
        Ptr<SVM> para = imgPreProcessAndTrain();
        string path = "d:/image/pre/k04_s.png";
        Mat feature_mat = processImage(path);
        Mat input;
        input.push_back(feature_mat);
        input.convertTo(input, CV_32F);//更改图片数据的类型
        float r = para->predict(input);   //对所有行进行预测
        cout << "the sorce is  "<< (char)r << endl;
    }
};
