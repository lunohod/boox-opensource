#ifndef PAGESCRIBBLE_H
#define PAGESCRIBBLE_H

#include <vector>

#include "PAPoint.h"
#include "PARect.h"

namespace pdfanno {
struct PageScribble {
    struct Stroke {
        PARect rect_;
        std::vector<PAPoint> points_;
        double thickness_;

        Stroke(std::vector<PAPoint> points, double thickness = 1.0)
        {
            rect_ = PARect(points.front(), points.front());
            for (std::vector<PAPoint>::iterator it = points.begin(); it != points.end(); it++) {
                points_.push_back(*it);
                rect_.inflateTo(*it);
            }
            thickness_ = thickness;
        }
    };

    int page_;
    std::vector<Stroke> strokes_;
};

} // namespace

#endif // PAGESCRIBBLE_H
