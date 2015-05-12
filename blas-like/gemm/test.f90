program test
    use ISO_FORTRAN_ENV
    use OMP_LIB
    implicit none
    integer :: err
    integer :: argnum, arglen
    character(len=32) :: argtmp
    integer :: r, dims(3), m, n, k
    real(kind=REAL128), allocatable :: x128(:,:), y128(:,:), z128(:,:)
    double precision :: t0,t1,dt
    dims(:) = 100
    do argnum = 1, command_argument_count()
        call get_command_argument(argnum,argtmp,arglen,err)
        !print*,'get_command_argument: ',argnum,argtmp,arglen,err
        if (err.eq.0) read(argtmp,'(i)') dims(argnum)
    enddo
    m = dims(1)
    n = dims(2)
    k = dims(3)
    print*,'(m,n,k) = ',m,n,k
    allocate( x128(m,k) )
    allocate( y128(k,n) )
    allocate( z128(m,n) )
    call random_seed()
    call random_number(x128)
    call random_number(y128)
    call random_number(z128)
!    do i=1,n
!      write(6,1128) i,x128(i),y128(i)
!    enddo
    dt = 0.0d0
    do r=1,10
        t0 = omp_get_wtime()
        call matmulf128(m,n,k,x128,y128,z128)
        t1 = omp_get_wtime()
        dt = dt + t1 - t0
    enddo
    write(6,1000) dt/r
    deallocate( x128 )
    deallocate( y128 )
    deallocate( z128 )
 1128 format(' float128 ',i9,',',e35.28,',',e35.28)
 1000 format('Timing ',f14.7)
end program test
