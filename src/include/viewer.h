#ifndef VIEWER_H_
#define VIEWER_H_

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui.hpp"

namespace viewer{

class Viewer{
    public:
        Viewer(void);
    private:
        cv::Mat canvas;
};

}	// namespace viewer

#endif // VIEWER_H_