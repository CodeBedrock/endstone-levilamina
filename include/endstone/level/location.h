// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
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

#pragma once

#include <memory>

#include "endstone/level/position.h"
#include "endstone/util/vector.h"

namespace endstone {

class Location : Position {
public:
    Location(const std::weak_ptr<Level> &level, const std::weak_ptr<Dimension> &dimension, double x, double y,
             double z, float pitch = 0.0, float yaw = 0.0)
        : Position(level, dimension, x, y, z), pitch_(pitch), yaw_(yaw)
    {
    }

    [[nodiscard]] float getPitch() const
    {
        return pitch_;
    }

    void setPitch(float pitch)
    {
        pitch_ = pitch;
    }

    [[nodiscard]] float getYaw() const
    {
        return yaw_;
    }

    void setYaw(float yaw)
    {
        yaw_ = yaw;
    }

private:
    float pitch_;  // Rotation around the right axis (around X axis).
    float yaw_;    // Rotation around the up axis (around Y axis)
};

}  // namespace endstone
