#include <testlib/testlib_test.h>
#include <vcl_iostream.h>
#include <vpgl/vpgl_perspective_camera.h>
#include <vpgl/io/vpgl_io_perspective_camera.h>
#include <vnl/vnl_double_3.h>
#include <vpl/vpl.h>
#include <vsl/vsl_binary_io.h>
#include <vgl/io/vgl_io_point_3d.h>

static void test_perspective_camera_io()
{
  vcl_cout << "Testing perspective camera" << vcl_endl;

  // ===========  Construct the camera

  double data[] = { 2000,    0, 512,
                    0, 2000, 384,
                    0,    0,   1 };
  vpgl_calibration_matrix<double> K = vnl_double_3x3(data);
  vgl_homg_point_3d<double>center(0,0,-10.0);

  // rotation angle in radians
  double theta = vnl_math::pi_over_4; // 45 degrees
  // y axis is the rotation axis
  vnl_double_3 axis(0.0, 1.0, 0.0);
  vgl_h_matrix_3d<double> R;
  R.set_identity().set_rotation_about_axis(axis, theta);
  vcl_cout <<"Rotation Matrix\n" << R << '\n';
  vpgl_perspective_camera<double> P(K, center, vgl_rotation_3d<double>(R));

  vcl_cout << "Camera " << P;

  // test output

  vsl_b_ofstream bp_out("test_perspective_camera_io.tmp");
  TEST("Created test_perspective_camera_io.tmp for writing",(!bp_out), false);
  vsl_b_write(bp_out, P);
  bp_out.close();

  // test input binary stream

  vsl_b_ifstream bp_in("test_perspective_camera_io.tmp");
  TEST("Opened test_perspective_camera_io.tmp for reading",(!bp_in), false);

  vpgl_perspective_camera<double> P_r;
  vsl_b_read(bp_in, P_r);
  bp_in.close();
  vpl_unlink("test_perspective_camera_io.tmp");
  vcl_cout << "Recovered Camera " << P_r;
  TEST("recovered camera", P, P_r);
}

TESTMAIN(test_perspective_camera_io);