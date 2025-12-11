.text
    .globl _main

_main:
  mov $6, %rcx
  mov $7, %rdx
  mov $0, %r8 # 0 for addition, 1 for multiplication

  movl %ecx, %edi
  movl %edx, %esi

  cmp $0, %r8
  jne skip_addition
  call addition
  jmp endifblock

skip_addition:
  cmp $1, %r8
  jne endifblock
  call multiplication
  jmp endifblock

endifblock:
  mov $0x2000001, %rax
  mov $0, %rdi
  syscall

addition:
  # save on stack, not needed but good practice
  push %rbp
  mov %rsp, %rbp
  mov %edi, -0x4(%rbp)
  mov %esi, -0x8(%rbp)
  add %edi, %esi
  mov %esi, %eax
  pop %rbp
  ret

multiplication:
  push %rbp
  mov %rsp, %rbp
  mov %edi, -0x4(%rbp)
  mov %esi, -0x8(%rbp)
  mov %edi, %eax
  imul %esi, %eax
  pop %rbp
  ret
