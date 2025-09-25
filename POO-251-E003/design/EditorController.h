// include/editor/EditorController.h

#pragma once

#include "Canvas.h"
#include "View.h"
#include "Point.h"
#include <vector>
#include <string>

class EditorController {
    public:
        EditorController(Canvas& canvas, View& view);

        void addPolygon(const std::vector<Point>& vertices);
        void renderCurrentCanvas();
        void saveCanvasToFile(const std::string& filename);

    private:
        Canvas& model;
        View& view;
};