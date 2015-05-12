subroutine matmulf128(m,n,k,alpha,x,y,beta,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: m,n,k
    real(kind=REAL128), intent(in) :: alpha, beta
    real(kind=REAL128), intent(in) :: x(m,k),y(k,n)
    real(kind=REAL128), intent(inout) :: z(m,n)
    return
end subroutine matmulf128
