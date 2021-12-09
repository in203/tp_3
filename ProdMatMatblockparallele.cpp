#include <algorithm>
#include <cassert>
#include <iostream>
#include <thread>
#include<omp.h>
#include "ProdMatMat.hpp"

/*namespace {
void prodSubBlocks(int iRowBlkA, int iColBlkB, int iColBlkA, int szBlock,
                   const Matrix& A, const Matrix& B, Matrix& C) {
                    

                     
      
       
        
}

                   
}  // namespace*/
const int szBlock = 510;
// on travaille ici par block
Matrix operator*(const Matrix& A, const Matrix& B) {
  Matrix C(A.nbRows, B.nbCols, 0.0);
  #pragma omp parallel for//distribution des itérations aux threads
  
  for (int jj=0;jj<B.nbCols;jj+=szBlock){
    for(int kk=0;kk<A.nbCols;kk+=szBlock){
      for(int ii=0;ii<A.nbRows;ii+=szBlock){
        for (int j = jj; j < std::min(B.nbCols, jj + szBlock); j++){
            for (int k = kk; k < std::min(A.nbCols, kk+ szBlock); k++){
                    
               for (int i = ii ;i < std::min(A.nbRows, ii + szBlock); i++){

                   C(i, j) += A(i, k) * B(k, j);

                         }
                      }
                    }
                }    
              }
           }
  return C;
}
