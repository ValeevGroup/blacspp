#include <blacspp/wrappers/broadcast.hpp>

using blacspp::blacs_int;
using blacspp::scomplex;
using blacspp::dcomplex;

// Prototypes
extern "C" {


// Send
void Cigebs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP, 
               const blacs_int M, const blacs_int N, const blacs_int* A, 
               const blacs_int LDA );
void Csgebs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP, 
               const blacs_int M, const blacs_int N, const float* A, 
               const blacs_int LDA );
void Cdgebs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP, 
               const blacs_int M, const blacs_int N, const double* A, 
               const blacs_int LDA );
void Ccgebs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP, 
               const blacs_int M, const blacs_int N, const scomplex* A, 
               const blacs_int LDA );
void Czgebs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP, 
               const blacs_int M, const blacs_int N, const dcomplex* A, 
               const blacs_int LDA );

void Citrbs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, const blacs_int* A, const blacs_int LDA ); 
void Cstrbs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, const float* A, const blacs_int LDA ); 
void Cdtrbs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, const double* A, const blacs_int LDA ); 
void Cctrbs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, const scomplex* A, const blacs_int LDA ); 
void Cztrbs2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, const dcomplex* A, const blacs_int LDA ); 

// Recv
void Cigebr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const blacs_int M, const blacs_int N, blacs_int* A, 
               const blacs_int LDA );
void Csgebr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const blacs_int M, const blacs_int N, float* A, 
               const blacs_int LDA );
void Cdgebr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const blacs_int M, const blacs_int N, double* A, 
               const blacs_int LDA );
void Ccgebr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const blacs_int M, const blacs_int N, scomplex* A, 
               const blacs_int LDA );
void Czgebr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const blacs_int M, const blacs_int N, dcomplex* A, 
               const blacs_int LDA );

void Citrbr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, blacs_int* A, const blacs_int LDA ); 
void Cstrbr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, float* A, const blacs_int LDA ); 
void Cdtrbr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, double* A, const blacs_int LDA ); 
void Cctrbr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, scomplex* A, const blacs_int LDA ); 
void Cztrbr2d( const blacs_int ICONTXT, const char* SCOPE, const char* TOP,
               const char* UPLO, const char* DIAG, const blacs_int M, 
               const blacs_int N, dcomplex* A, const blacs_int LDA ); 

}



namespace blacspp {
namespace wrappers {

// Send

// GEBS2D
#define gebs2d_impl( fname, type ) \
template <>                                                    \
void gebs2d<type>(                                             \
  const blacs_int ICONTXT, const char* SCOPE, const char* TOP, \
  const blacs_int M, const blacs_int N, const type* A,         \
  const blacs_int LDA ) {                                      \
                                                               \
  fname( ICONTXT, SCOPE, TOP, M, N, A, LDA );                  \
                                                               \
}

gebs2d_impl( Cigebs2d, blacs_int );
gebs2d_impl( Csgebs2d, float     );
gebs2d_impl( Cdgebs2d, double    );
gebs2d_impl( Ccgebs2d, scomplex  );
gebs2d_impl( Czgebs2d, dcomplex  );


// TRBS2D
#define trbs2d_impl( fname, type ) \
template <>                                                                 \
void trbs2d<type>(                                                          \
  const blacs_int ICONTXT, const char* SCOPE, const char* TOP,              \
  const char* UPLO, const char* DIAG, const blacs_int M, const blacs_int N, \
  const type* A, const blacs_int LDA ) {                                    \
                                                                            \
  fname( ICONTXT, SCOPE, TOP, UPLO, DIAG, M, N, A, LDA );                   \
                                                                            \
}

trbs2d_impl( Citrbs2d, blacs_int );
trbs2d_impl( Cstrbs2d, float     );
trbs2d_impl( Cdtrbs2d, double    );
trbs2d_impl( Cctrbs2d, scomplex  );
trbs2d_impl( Cztrbs2d, dcomplex  );











// Recv
  
// GEBR2D
#define gebr2d_impl( fname, type ) \
template <>                                                              \
void gebr2d<type>(                                                       \
  const blacs_int ICONTXT, const char* SCOPE, const char* TOP,           \
  const blacs_int M, const blacs_int N, type* A, const blacs_int LDA ) { \
                                                                         \
  fname( ICONTXT, SCOPE, TOP, M, N, A, LDA );                            \
                                                                         \
}

gebr2d_impl( Cigebr2d, blacs_int );
gebr2d_impl( Csgebr2d, float     );
gebr2d_impl( Cdgebr2d, double    );
gebr2d_impl( Ccgebr2d, scomplex  );
gebr2d_impl( Czgebr2d, dcomplex  );


// TRBR2D
#define trbr2d_impl( fname, type ) \
template <>                                                    \
void trbr2d<type>(                                             \
  const blacs_int ICONTXT, const char* SCOPE, const char* TOP, \
  const char* UPLO, const char* DIAG, const blacs_int M,       \
  const blacs_int N, type* A, const blacs_int LDA ) {          \
                                                               \
  fname( ICONTXT, SCOPE, TOP, UPLO, DIAG, M, N, A, LDA );      \
                                                               \
}

trbr2d_impl( Citrbr2d, blacs_int );
trbr2d_impl( Cstrbr2d, float     );
trbr2d_impl( Cdtrbr2d, double    );
trbr2d_impl( Cctrbr2d, scomplex  );
trbr2d_impl( Cztrbr2d, dcomplex  );


}
}

