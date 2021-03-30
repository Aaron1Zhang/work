#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <memory>
#include <functional>
#include <QDebug>
using namespace std;

struct OriginalDataInfo {
    std::string measure_name;
    float k;
    float b;
    float tolerance; //min tolerance
    std::multimap<double, double> pixel_threeD_datas;  //像素距离作为key, 三次元作为value
    OriginalDataInfo() = default;
    OriginalDataInfo(const string& name, float m_k, float m_b, float t, const multimap<double, double>& p_threeD):
             measure_name{name}, k{m_k}, b{m_b}, tolerance{t},  pixel_threeD_datas {p_threeD} {}
};

struct AdjustDataInfo {
    std::string item_name; //测量项目：eg:FAI24
    std::multimap<double, double> item_data; //key为pixel,value为predict_data}
};

class PixelOutliersClassify {
private:
    std::map<string, OriginalDataInfo> data_info;
    std::string statis_path;
    std::map<string, vector<vector<double>>> range_info;
    std::map<string, vector<vector<double>>> read_info;

    double calcCoeffi(std::vector<pair<double, double>>& outlier_points, double threeD_aveage, float t, string name, float delta = 0.001) {
//        std::multimap<double, pair<double, double>> sub_vector;  //pair数据为预测值和对应的三次元数据
//        for_each(outlier_points.begin(), outlier_points.end(), [&sub_vector](const auto& data) {
//            sub_vector.insert(make_pair(abs(data.first - data.second), make_pair(data.first, data.second)));

//        });

//        auto p = sub_vector.begin()->second;
//        return  (p.second - t)/(p.first + threeD_aveage);

        std::multimap<size_t, double> error_count2_p;
        for(size_t i{0}; i < outlier_points.size(); ++i) {
            auto p = (outlier_points[i].second - delta) / (outlier_points[i].first + threeD_aveage);
            auto f = [=] () mutable {
                size_t bad_data_count{0};
                outlier_points.erase(outlier_points.begin()+i);
                for(const auto& data: outlier_points) {
                    bad_data_count += abs((data.first + threeD_aveage) * p - data.second) >= t? 1: 0;

                }
                return bad_data_count;
            };
            error_count2_p.insert({f(), p});
        }
        qDebug() << "outlier_points info begin" << QString::fromStdString(name) << endl;
        for(auto data: outlier_points) {
            qDebug() << "predictied data " << data.first << " threeD data" << data.second << endl;
        }
        qDebug() << "error_count2_p begin********" << endl;
        for(auto& error: error_count2_p) {
            qDebug() << "error count " << error.first << " p " << error.second << endl;
        }
        qDebug() << "error_count2_p end------------" << endl;
        qDebug() << "outlier_points info end" << QString::fromStdString(name) << endl;
        return error_count2_p.begin()->second;
    }

    template <typename iter>
    void calcAdjustData(iter item_iterator, double range_limit = 0.00002) {
        auto item_name = item_iterator.measure_name;
        auto k = item_iterator.k;
        auto b = item_iterator.b;
        auto t = item_iterator.tolerance;
        auto pixel_threeD_datas = item_iterator.pixel_threeD_datas;
        auto pixel_threeD_datas_size = pixel_threeD_datas.size();
        decltype (pixel_threeD_datas.size()) pixel_threeD_datas_count{0};

        bool outlier_frist_flag = false;
        double outlier_pixel_left;
        double outlier_pixel_right;
        double outlier_sum{0};
        size_t outlier_count{0};
        std::vector<pair<double, double>> outlier_points;

        for(const auto& pixel_threeD_data: pixel_threeD_datas) {
            pixel_threeD_datas_count++;
            auto pixel_data = pixel_threeD_data.first;
            auto threeD_data = pixel_threeD_data.second;
            auto predicit_data = calcPredicitData(pixel_data, k, b);

            if(isOutlierPoint(predicit_data, threeD_data, t)) {
                outlier_points.push_back(make_pair(predicit_data, threeD_data));  //new line

                if(outlier_frist_flag == false) {
                    outlier_frist_flag = true;
                    outlier_pixel_left = pixel_data;
                }
                outlier_pixel_right = pixel_data;
                outlier_sum += threeD_data;
                outlier_count++;
                if(pixel_threeD_datas_count == pixel_threeD_datas_size) {
                    auto outlier_threeD_aveage = outlier_sum / outlier_count;
                    auto p = calcCoeffi(outlier_points, outlier_threeD_aveage, t, item_name); // new line
                    range_info[item_name].push_back({outlier_pixel_left-range_limit, outlier_pixel_right+range_limit, outlier_threeD_aveage, p});

                }

            } else{
                outlier_frist_flag = false;
                if(outlier_count != 0) {
                    auto outlier_threeD_aveage = outlier_sum / outlier_count;
                    auto p = calcCoeffi(outlier_points, outlier_threeD_aveage, t, item_name); // new line
                    range_info[item_name].push_back({outlier_pixel_left-range_limit, outlier_pixel_right+ range_limit, outlier_threeD_aveage, p});

                }
                outlier_sum = 0;
                outlier_count = 0;
                outlier_points.clear();
            }
        }
    }

    double calcPredicitData(double pixel_data, float k, float b) {
        cout << "pixel data " << pixel_data << " predict data: " << k*pixel_data + b << endl;
        return k*pixel_data + b;
    }

    bool isOutlierPoint(double predicit, double threeD_data, double tolerance, float p = 1) {
        cout << "threeD_data: " << threeD_data << "error " << threeD_data-predicit << endl;
        if(abs(threeD_data-predicit) >= p*tolerance) {
            return true;
        }
        return false;
    }

    void genStatisOutlierXML() {
        if(range_info.empty()) {
            cout << "no outlier info, don not gen xml" << endl;
            return;
        }
        QFile file(QString::fromStdString(statis_path));
        QXmlStreamWriter writer;
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            cout << "file error" << endl;
            return;
        }
        writer.setDevice(&file);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();
        writer.writeStartElement("opencv_storage");
        size_t range_index{1};
        for(const auto& ri: range_info) {
            writer.writeStartElement("item");
            writer.writeAttribute("name", QString::fromStdString(ri.first));
            for(const auto& data: ri.second) {
                writer.writeStartElement("range");
                writer.writeAttribute("index", QString::number(range_index));
                writer.writeTextElement("left", QString::number(data[0], 'g', 10));
                writer.writeTextElement("right", QString::number(data[1], 'g', 10));
                writer.writeTextElement("aveage", QString::number(data[2], 'g', 10));
                writer.writeTextElement("p", QString::number(data[3], 'g', 10));
                writer.writeEndElement();
                range_index++;
            }
            range_index = 1;
            writer.writeEndElement();

        }
        writer.writeEndDocument();
    }

    void readStatisOutlierXML() {
        QFile file(QString::fromStdString(statis_path));
        QXmlStreamReader reader;
        if(!file.open(QFile::ReadOnly | QFile::Text)) {
            throw std::string("can not open the file");
        }
        reader.setDevice(&file);
        string item_name;
        double left;
        double right;
        double aveage;
        double p;
        map<string, function<void()>> xmlParseHandlers;

        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.isStartElement()) {
                if(reader.name() == "item") {
                    item_name = reader.attributes().value("name").toString().toStdString();
                }
                else if(reader.name() == "range") {
                    //cout << reader.name().toString().toStdString() << ": ";
                    //cout << reader.attributes().value("index").toString().toStdString() << endl;
                }
                else if(reader.name() == "left") {
                    left = reader.readElementText().toDouble();
                }
                else if(reader.name() == "right") {
                    right = reader.readElementText().toDouble();
                }
                else if(reader.name() == "aveage") {
                    aveage = reader.readElementText().toDouble();
                }
                else if(reader.name() == "p") {
                    p = reader.readElementText().toDouble();
                }
            }
            else {
                if(reader.isEndElement() && reader.name() == "range") {
                    read_info[item_name].push_back({left, right, aveage, p});
                }

            }
        }

    }
    template<typename iter>
    bool isInOutlierRange(iter range_iter, double pixel_data, double& predicit_data) {
        vector<vector<double>> ranges = range_iter->second;
        for(const auto& range: ranges) {
            auto left = range[0];
            auto right = range[1];
            auto aveage = range[2];
            auto p = range[3];
            cout << "pixel data is " << pixel_data << " left " << left << " right " << right << " aveage " << aveage << " p " << p << endl;
            if((pixel_data > left) && (pixel_data < right)) {
                predicit_data = (predicit_data + aveage)*p;
                return true;
            }
        }
        return false;
    }

public:

    PixelOutliersClassify(const std::map<string, OriginalDataInfo>& data_in, const std::string& path):
        data_info{data_in}, statis_path{path} {}

    PixelOutliersClassify(const std::string& path): statis_path{path} {}

    void StatisOutlier() {
        for(auto& item: data_info) {
            calcAdjustData(item.second);
        }
        genStatisOutlierXML();
    }

    void adjustOutlierData(vector<AdjustDataInfo>* datas_ptr) {
        readStatisOutlierXML();
        for(auto& item: *datas_ptr) {
            auto item_name = item.item_name;
            auto& item_d = item.item_data;
            auto find_iter = read_info.find(item_name);
            if(find_iter == read_info.end()) {
                continue;
            }
            for(auto& map_pair: item_d) {
                auto pixel_data = map_pair.first;
                auto& predicit_data = map_pair.second;
                if(isInOutlierRange(find_iter, pixel_data, predicit_data)) {
                    map_pair.second = predicit_data;
                    cout << "update prediction" << map_pair.second << endl;
                }
            }
        }
    }

    static void Test() {
        std::map<string, OriginalDataInfo> data;
        multimap<double, double> pixel_threeD_datas{{3545.2, 35.688},{3546.9, 35.691},
                                                    {3550.2, 35.671},{3550.97, 35.666},
                                                    {3551.79, 35.69},{3552.64, 35.693},
                                                    {3554.36,35.709},{3554.44,35.719},
                                                    {3556.5, 35.729}, {3557.92,35.718}};

        multimap<double, double> pixel_threeD_datas1{{2976.35, 29.949},{2976.35, 30.018}};

        data["FAI25"] = OriginalDataInfo{"FAI25", 0.003187592839822, 24.377351760864258, 0.03, pixel_threeD_datas};
        //data["FAI26"] = OriginalDataInfo{"FAI26", 1, 0, 0.15, pixel_threeD_datas1};


        std::string path = "C:/Users/Administrator/Desktop/proj_templates/452_proj/test_write1.xml";
        PixelOutliersClassify pixel_class(data, path);
        pixel_class.StatisOutlier();
       // pixel_class.readStatisOutlierXML();
        multimap<double, double> datas = {{1.5,1.6},{1,1.2}, {2.1, 2.2}};
         //map<string, pair<double, double>> datas1 = {};
        vector<AdjustDataInfo> d = {{"FAI25", datas}};

        //unique_ptr<vector<AdjustDataInfo>> ptr = make_unique<vector<AdjustDataInfo>>(d);
        vector<AdjustDataInfo>* ptr = new vector<AdjustDataInfo>(d);
        //pixel_class.adjustOutlierData(ptr.get());

         PixelOutliersClassify adjust(path);
         adjust.adjustOutlierData(ptr);
        //pixel_class.adjustOutlierData(ptr);
        //auto change_data = *(ptr.get());
        auto change_data = *ptr;
        cout << "------------------------" << endl;
        for(auto& item: change_data) {
            cout << item.item_name << endl;
            for(auto& data: item.item_data) {
                cout << "pixel data:" << data.first << " ";
                cout << "prediction change : " << data.second << endl;
            }
        }

    }
};


