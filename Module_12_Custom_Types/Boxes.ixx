module;

export module Boxes;

using ItemType = unsigned int;

namespace Boxes {
    export class PlainBox {
        ItemType item{};

    public:
        PlainBox() = default;

        PlainBox(const ItemType &item);

        auto setItem(const ItemType &item) -> void;

        auto getItem() const -> ItemType;
    };
}
