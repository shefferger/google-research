// Copyright 2020 The Google Research Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SCANN__OSS_WRAPPERS_SCANN_MALLOC_EXTENSION_H_
#define SCANN__OSS_WRAPPERS_SCANN_MALLOC_EXTENSION_H_

#include <stddef.h>

#include "absl/strings/string_view.h"
#include "absl/types/optional.h"

namespace tensorflow {
namespace scann_ops {

class MallocExtension {
 public:
  void GetNumericProperty(absl::string_view property, size_t* value) {}
  static absl::optional<size_t> GetNumericProperty(absl::string_view property) {
    return absl::nullopt;
  }
  void ReleaseFreeMemory() {}
  size_t GetAllocatedSize(const void* p) { return 0; }
  static MallocExtension* instance();

 private:
  static MallocExtension singleton;
};

}  // namespace scann_ops
}  // namespace tensorflow

#endif
