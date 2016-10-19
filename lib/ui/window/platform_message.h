// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_PLATFORM_PLATFORM_MESSAGE_H_
#define FLUTTER_LIB_UI_PLATFORM_PLATFORM_MESSAGE_H_

#include <string>
#include <vector>

#include "flutter/lib/ui/window/platform_message_response.h"
#include "lib/ftl/memory/ref_counted.h"
#include "lib/ftl/memory/ref_ptr.h"

namespace blink {

class PlatformMessage : public ftl::RefCountedThreadSafe<PlatformMessage> {
  FRIEND_REF_COUNTED_THREAD_SAFE(PlatformMessage);
  FRIEND_MAKE_REF_COUNTED(PlatformMessage);

 public:
  const std::string& name() const { return name_; }
  const std::vector<uint8_t>& data() const { return data_; }

  const ftl::RefPtr<PlatformMessageResponse>& response() const {
    return response_;
  }

 private:
  PlatformMessage(std::string name,
                  std::vector<uint8_t> data,
                  ftl::RefPtr<PlatformMessageResponse> response);
  ~PlatformMessage();

  std::string name_;
  std::vector<uint8_t> data_;
  ftl::RefPtr<PlatformMessageResponse> response_;
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_PLATFORM_PLATFORM_MESSAGE_H_