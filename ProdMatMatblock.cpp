#include <algorithm>
#include <cassert>
#include <iostream>
#include <thread>

#include "ProdMatMat.hpp"

namespace {
void prodSubBlocks(int iRowBlkA, int iColBlkB, int iColBlkA, int szBlock,
                   const Matrix& A, const Matrix& B, Matrix& C) {
                    

   

                     for (int j = iColBlkB; j < std::min(B.nbCols, iColBlkB + szBlock); j++)
   
                     for (int k = iColBlkA; k < std::min(A.nbCols, iColBlkA + szBlock); k++)
                    for (int i = iRowBlkA; i < std::min(A.nbRows, iRowBlkA + szBlock); ++i)
 
    
      
        C(i, j) += A(i, k) * B(k, j);//affectation ce n'estpas arithmetique
}
const int szBlock = 510;
                   
}  // namespace
      
       
// on travaille ici par block
Matrix operator*(const Matrix& A, const Matrix& B) {
  Matrix C(A.nbRows, B.nbCols, 0.0);
  for (int jj=0;jj<B.nbCols;jj+=szBlock){
    for(int kk=0;kk<A.nbCols;kk+=szBlock){
      for(int ii=0;ii<A.nbRows;ii+=szBlock){
        prodSubBlocks(ii , jj , kk ,szBlock,A,  B,  C);
                    
                }    
              }
           }
  return C;
}
