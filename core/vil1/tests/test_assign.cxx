#include <vcl/vcl_iostream.h>
#include <vil/vil_load.h>

int main(int argc, char **argv)
{
  vil_image image;
  for (int i=1; i<argc; ++i) {
    vil_image tmp( vil_load(argv[i]) );
    cerr << "tmp = " << tmp << endl;
    image = tmp;
  }
    
  return 0;
}
