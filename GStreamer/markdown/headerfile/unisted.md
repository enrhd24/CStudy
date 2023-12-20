# headerfile

- POSIX 운영체제 API에 대한 액세스를 제공하는 헤더파일
- 내용 읽고 쓰기

## function

- read function : 파일에서 데이터를 읽기
    - ssize_t read(int fd, void* buf, size_t nbytes)
        - fd : 파일 식별자
        - buf : 데이터를 저장하는 버퍼
        - nbytes : 읽어올 바이트 수
        - return -> 성공:읽은 바이트수 , 실패:-1
- write function : 파일에서 데이터 쓰기
    - ssize_t write(int fd, void*buf, size_t nbytes)
        - fd : 파일 식별자
        - buf : 데이터를 저장하고있는 버퍼
        - nbytes : 쓸 바이트 수
        - reurn -> 성공:파일에 쓴 바이트 수 , 실패:-1

### Link

- https://www.it-note.kr/category/C%EC%96%B8%EC%96%B4%20header/unistd.h?page=1
