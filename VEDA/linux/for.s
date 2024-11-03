.global main      // main 함수를 글로벌 심볼로 선언합니다.
.text             // 코드 섹션 시작.

main:  
    stp x29, x30, [sp, -16]!  // 스택에 x29와 x30을 저장하고, 스택 포인터를 조정.
    mov x29, sp               // 프레임 포인터 설정.

    mov w0, 1                 // w0에 초기값 1 저장 (1부터 시작).
loop:
    // printf를 호출하기 위해 준비.
    mov x1, w0                // 출력할 정수를 x1에 저장.
    ldr x0, =format_string    // 포맷 문자열 주소를 x0에 로드.
    bl printf                 // printf 호출.

    add w0, w0, 1             // w0 값을 1 증가.
    cmp w0, 11                // w0과 11을 비교 (10까지 출력하기 위함).
    bne loop                  // w0이 11이 아니면 loop 라벨로 분기.

    ldp x29, x30, [sp], 16    // 스택에서 x29, x30을 복원.
    mov x0, xzr               // x0에 0 저장 (반환값).
    ret                       // 함수 종료.

.data                         // 데이터 섹션 시작.
format_string: .asciz "%d\n"  // 정수 출력 포맷 문자열.
