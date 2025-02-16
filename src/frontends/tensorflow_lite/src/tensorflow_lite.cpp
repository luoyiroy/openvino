// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "openvino/frontend/manager.hpp"
#include "openvino/frontend/tensorflow_lite/frontend.hpp"
#include "openvino/frontend/tensorflow_lite/visibility.hpp"

TENSORFLOW_LITE_C_API ov::frontend::FrontEndVersion GetAPIVersion() {
    return OV_FRONTEND_API_VERSION;
}

TENSORFLOW_LITE_C_API void* GetFrontEndData() {
    auto res = new ov::frontend::FrontEndPluginInfo();
    res->m_name = "tflite";
    res->m_creator = []() {
        return std::make_shared<ov::frontend::tensorflow_lite::FrontEnd>();
    };
    return res;
}
