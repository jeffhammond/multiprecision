subroutine matmulf128(row,col,inn,x,y,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: row, col, inn
    real(kind=REAL128), intent(in) :: x(row,inn),y(inn,col)
    real(kind=REAL128), intent(inout) :: z(row,col)
    integer :: i,j,k
    do i=1, row
      do j=1, col
        do k=1, inn
          z(i,j) = z(i,j) + x(i,k) * y(k,j)
        enddo
      enddo
    enddo
    return
end subroutine matmulf128
