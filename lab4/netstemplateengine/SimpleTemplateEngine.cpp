//
// Created by krzysztof on 26.03.18.
//

#include "SimpleTemplateEngine.h"

namespace nets {
    View::View() {
        view1 = "";
        vector_view = {};
    }
    View::View(std::string view) {
        std::string w_1 = "";
        std::string w_2 = "";
        view1 = view;
        int j = 0;
        for (int i = 0; i < view.size(); i++)
        {
            if (view[i] != '{') {
                w_1 = w_1 + view[i];
            } else {
                if (i + 1 < view.size() && view[i + 1] != '{') {
                    w_1 = w_1 + view[i];
                } else {
                    w_2 = w_2 + view[i] + view[i + 1];
                    j = i + 2;
                    for (j; j < view.size(); j++) {
                        if ((97 <= view[j] && view[j] <= 122) || (65 <= view[j] && view[j] <= 90) ||
                            (48 <= view[j] && view[j] <= 57) || view[j] == 95) {
                            w_2 = w_2 + view[j];
                        } else {
                            if (view[j] == '}' && (j + 1 < view.size() && view[j + 1] == '}')) {
                                w_2 = w_2 + view[j] + view[j + 1];
                                vector_view.push_back(w_1);
                                vector_view.push_back(w_2);
                                w_1 = "";
                                w_2 = "";
                                i = j + 1;
                                break;
                            } else {
                                w_1 = w_1 + w_2[0];
                                w_2 = "";
                                break;
                            }
                        }
                    }
                }
            }
            if (w_1 != "" && i + 1 == view.size()) {
                vector_view.push_back(w_1);
            }
        }
    }

    View::~View() {
        vector_view.clear();
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::cout << std::endl;
        std::string result = "";
        std::string model_with_brackets = "";
        for (auto i : vector_view) {
            if (i[0] == '{' && i[1] == '{' && i[i.size() - 2] == '}' && i[i.size() - 1] == '}') {
                for (auto j : model) {
                    model_with_brackets = "{{" + j.first + "}}";
                    if (model_with_brackets == i) {
                        result = result + j.second;
                    }
                }
            } else {
                result = result + i;
            }
        }
        return result;
    }
}