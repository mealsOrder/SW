#include "user.h"

int save_user_to_csv(UserData *user_data) {
    FILE *file = fopen(CSV_FILE, "a");  
    if (file == NULL) {
        perror("Failed to open file");
        return 0;
    }
    fprintf(file, "%s,%s\n", user_data->id, user_data->password);
    fclose(file);
    return 1;
}

int check_login_from_csv(UserData *user_data) {
    FILE *file = fopen(CSV_FILE, "r");  
    if (file == NULL) {
        perror("Failed to open file");
        return 0;
    }

    char line[256];
    char id[20], password[20];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%s", id, password); 
        if (strcmp(user_data->id, id) == 0 && strcmp(user_data->password, password) == 0) {
            fclose(file);
            return 1;  // 로그인 성공
        }
    }
    fclose(file);
    return 0;  // 로그인 실패
}

// 회원가입 함수
int signup(UserData *user_data) {
    // 유저 정보를 CSV에 저장
    if (save_user_to_csv(user_data)) {
        return 1;  // 회원가입 성공
    } else {
        return 0;  // 회원가입 실패
    }
}

// 로그인 함수
int login(UserData *user_data) {
    // CSV 파일에서 유저 정보를 확인
    if (check_login_from_csv(user_data)) {
        return 1;  // 로그인 성공
    } else {
        return 0;  // 로그인 실패
    }
}