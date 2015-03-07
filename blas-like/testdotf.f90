program testdotf
    use ISO_FORTRAN_ENV
    use OMP_LIB
    implicit none
    integer, parameter :: n=100000
    integer :: i,j
    real(kind=REAL128) :: x128(n),y128(n)
    real(kind=REAL128) :: z128
    real(kind=REAL64) :: x64(n),y64(n)
    real(kind=REAL64) :: z64
    real(kind=REAL32) :: x32(n),y32(n)
    real(kind=REAL32) :: z32
    double precision :: t0,t1,dt32,dt64,dt128
    call random_seed()
    call random_number(x128)
    call random_number(y128)
    do i=1,n
        x64(i) = x128(i)
        x32(i) = x128(i)
        y64(i) = y128(i)
        y32(i) = y128(i)
    enddo
!    do i=1,n
!      write(6,1128) i,x128(i),y128(i)
!    enddo
!    do i=1,n
!      write(6,164) i,x64(i),y64(i)
!    enddo
!    do i=1,n
!      write(6,132) i,x32(i),y32(i)
!    enddo
    dt128 = 0.0d0
    dt64  = 0.0d0
    dt32  = 0.0d0
    do j=1,20
        t0 = omp_get_wtime()
        call myqdot(n,x128,1,y128,1,z128)
        t1 = omp_get_wtime()
        dt128 = dt128 + t1 - t0
        t0 = omp_get_wtime()
        call myddot(n,x64 ,1,y64 ,1,z64)
        t1 = omp_get_wtime()
        dt64 = dt64 + t1 - t0
        t0 = omp_get_wtime()
        call mysdot(n,x32 ,1,y32 ,1,z32)
        t1 = omp_get_wtime()
        dt32 = dt32 + t1 - t0
        if (j.eq.1) then
            ! check accuracy visually on first iteration
            write(6,*) dt128,',',z128
            write(6,*) dt64,',',z64
            write(6,*) dt32,',',z32
            ! ignore timing for first iteration
            dt128 = 0.0d0
            dt64  = 0.0d0
            dt32  = 0.0d0
        endif
    enddo
    write(6,*) dt32,dt64,dt128
 132  format(' float32  ',i9,',',e14.7 ,',',e14.7)
 164  format(' float64  ',i9,',',e21.14,',',e21.14)
 1128 format(' float128 ',i9,',',e35.28,',',e35.28)
end program testdotf
