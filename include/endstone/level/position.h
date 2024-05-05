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

#include "endstone/util/vector.h"

namespace endstone {

class Level;
class Dimension;

class Position : Vector<double> {
public:
    Position(const std::weak_ptr<Level> &level, const std::weak_ptr<Dimension> &dimension, double x, double y,
             double z)
        : Vector(x, y, z), level_(level), dimension_(dimension)
    {
    }

    [[nodiscard]] const std::weak_ptr<Level> &getLevel() const
    {
        return level_;
    }

    void setLevel(const std::weak_ptr<Level> &level)
    {
        level_ = level;
    }

    [[nodiscard]] const std::weak_ptr<Dimension> &getDimension() const
    {
        return dimension_;
    }

    void setDimension(const std::weak_ptr<Dimension> &dimension)
    {
        dimension_ = dimension;
    }

private:
    std::weak_ptr<Level> level_;
    std::weak_ptr<Dimension> dimension_;
};

}  // namespace endstone
