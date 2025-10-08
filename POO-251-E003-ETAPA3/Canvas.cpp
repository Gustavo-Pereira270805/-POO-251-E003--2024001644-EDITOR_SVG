
#include "editor/Canvas.h"
#include <sstream>

Canvas::Canvas() {
}

    void Canvas::addShape(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }

    const std::vector<std::unique_ptr<Shape>>& Canvas::getShapes() const {
        return shapes;
    }

    std::string Canvas::toSVGFileString() const {
        std::stringstream ss;
        ss << "<svg width=\"800\" height=\"600\" xmlns=\"http://www.w3.org/2000/svg\">\n";

        for (const auto& shape_ptr : shapes) {
            ss << "  " << shape_ptr->toSVGString() << "\n";
        }

        ss << "</svg>";
        return ss.str();
}
    void Canvas::clearAllShapes()
    {
        shapes.clear();
    }
