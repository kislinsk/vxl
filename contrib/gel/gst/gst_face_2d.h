#ifndef gst_face_2d_h_
#define gst_face_2d_h_
#ifdef __GNUC__
#pragma interface
#endif
/*
  crossge@crd.ge.com
*/
#include <vcl_vector.h>
#include "gst_polygon_2d_sptr.h"

//: This class defines a simplified topology structure in 2D.
// It is light weight, and all interfacing should be done through the
// face class

class gst_face_2d
{
public:

  gst_face_2d( gst_polygon_2d_sptr polygon);
  gst_face_2d( gst_polygon_2d_sptr polygon, const vcl_vector<gst_polygon_2d_sptr> &holes);
  ~gst_face_2d();

protected:

  // outside edge list
  gst_polygon_2d_sptr outside_;

  // list of holes
  vcl_vector<gst_polygon_2d_sptr> holes_;
};


#endif
