main:
  # create 2 4x4 matrices in memory
  push %rbp
  mov %rsp, %rbp
  sub $64, %rsp    # 2 matrices x 4 rows x 8 byte pointers = 64 bytes space allocate on stack
  # matrix 1 at %rsp
  # matrix 2 at %rsp + 32 (offset 32)
  
  mov $0, %r15 

create_matrix:
  mov %rsp, %r12           # base address
  mov %r15, %r8            # matrix index
  imul $32, %r8            # matrix_index * 32
  add %r8, %r12            # %r12 = address of current matrix array

  mov $0, %r13             # row index init = 0

next_row:
  # 16 bytes each row
  mov $0x20000C5, %rax     # syscall number for mmap
  mov $0, %rdi             # 0/null (let os choose address)
  mov $16, %rsi            # 16 bytes
  mov $0x3, %rdx           # read + write
  mov $0x1002, %r10        # anonymous memory
  mov $-1, %r8             # no file
  mov $0, %r9              # no offset
  syscall                  # returns address in %rax

  mov %rax, (%r12, %r13, 8) # moves row address to rsp offset
  mov %rax, %rbx         # row pointer address

  # Manually set values for each row based on row index
  cmp $0, %r13
  je set_row0
  cmp $1, %r13
  je set_row1
  cmp $2, %r13
  je set_row2
  jmp set_row3

set_row0:
  movl $1, 0(%rbx)   # row 0, col 0
  movl $2, 4(%rbx)   # row 0, col 1
  movl $3, 8(%rbx)   # row 0, col 2
  movl $4, 12(%rbx)  # row 0, col 3
  jmp row_done

set_row1:
  movl $5, 0(%rbx)   # row 1, col 0
  movl $6, 4(%rbx)   # row 1, col 1
  movl $7, 8(%rbx)   # row 1, col 2
  movl $8, 12(%rbx)  # row 1, col 3
  jmp row_done

set_row2:
  movl $9, 0(%rbx)   # row 2, col 0
  movl $10, 4(%rbx)  # row 2, col 1
  movl $11, 8(%rbx)  # row 2, col 2
  movl $12, 12(%rbx) # row 2, col 3
  jmp row_done

set_row3:
  movl $13, 0(%rbx)  # row 3, col 0
  movl $14, 4(%rbx)  # row 3, col 1
  movl $15, 8(%rbx)  # row 3, col 2
  movl $16, 12(%rbx) # row 3, col 3

row_done:

  inc %r13
  cmp $4, %r13
  jl next_row

  inc %r15
  cmp $1, %r15
  je create_matrix

  mov %rsp, %rbx           # matrix 1 address
  lea 0x20(%rsp), %r12       # matrix 2 address

  mov %rbp, %rsp
  pop %rbp
  
  # load in 4x4 matrix from memory
load_mats:


  # load b1 to xmm0
  pinisrd %eax, %xmm0, 1 
  pinisrd %eax, %xmm0, 2
  pinisrd %eax, %xmm0, 3
  pinisrd %eax, %xmm0, 4

  # load b2 to xmm1
  pinisrd %eax, %xmm1, 1 
  pinisrd %eax, %xmm1, 2
  pinisrd %eax, %xmm1, 3
  pinisrd %eax, %xmm1, 4

  # load b3 to xmm2
  pinisrd %eax, %xmm2, 1 
  pinisrd %eax, %xmm2, 2
  pinisrd %eax, %xmm2, 3
  pinisrd %eax, %xmm2, 4

  # load b4 to xmm3
  pinisrd %eax, %xmm3, 1 
  pinisrd %eax, %xmm3, 2
  pinisrd %eax, %xmm3, 3
  pinisrd %eax, %xmm3, 4

  # broadcast a00
  mov -0x04(%rbp) %edx
  pinisrd %edx, %xmm8, 1
  pinisrd %edx, %xmm8, 2
  pinisrd %edx, %xmm8, 3
  pinisrd %edx, %xmm8, 4

  # broadcast a01
  mov -0x04(%rbp) %edx
  pinisrd %edx, %xmm9, 1
  pinisrd %edx, %xmm9, 2
  pinisrd %edx, %xmm9, 3
  pinisrd %edx, %xmm9, 4

    # broadcast a02
  mov -0x04(%rbp) %edx
  pinisrd %edx, %xmm10, 1
  pinisrd %edx, %xmm10, 2
  pinisrd %edx, %xmm10, 3
  pinisrd %edx, %xmm10, 4

  # broadcast a03
  mov -0x04(%rbp) %edx
  pinisrd %edx, %xmm11, 1
  pinisrd %edx, %xmm11, 2
  pinisrd %edx, %xmm11, 3
  pinisrd %edx, %xmm11, 4

  imul %xmm0, %xmm8
  imul %xmm1, %xmm9
  imul %xmm2, %xmm10
  imul %xmm3, %xmm11

  add xmm8, xmm9
  add xmm9, xmm10
  add xmm10, xmm11

  
