#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

int main(int argc, char** argv) {
    int i; //for loop index
    int length; //length of string to hash./
    unsigned char buffer[1024] = {0};
    char userid[16] = {0};
    char targetuid[] = "user1\n";
    char pw1[16] = {0}; //password entered by user
    char hash1[33] = {0}; //SHA256 hash of pw1 in bytes (32 bytes)
    char hash1hex[64]={0}; //hash1[] as a 64 long hex string
    //pw1: abcdefghi
    char target1[] = "19cc02f26df43cc571bc9ed7b0c4d29224a3ec229529221725ef76d021c8326f";
    char hash2[33] = {0};
    char hash2hex[64] = {0};
    //pw2: abcd
    char target2[] = "88d4266fd4e6338d13b845fcf289579d209c897823b9217da3e161936f031589";
    char hash3[33] = {0};
    char hash3hex[64] = {0};
    //pw3: abc
    char target3[] = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
    char pw2[16] = {0};
    char pw3[16] = {0};
    char* hash_ptr;

    printf("i addr: %p\n", (void *) &i );
    printf("i size: %d bytes\n\n", sizeof(i));

    printf("length addr: %p\n", (void *) &length );
    printf("length size: %d bytes\n\n", sizeof(length));

    printf("buffer addr: %p\n", (void *) &buffer );
    printf("buffer size: %d bytes\n\n", sizeof(buffer));

    printf("userid addr: %p\n", (void *) &userid );
    printf("userid size: %d bytes\n\n", sizeof(userid));

    printf("targetuid addr: %p\n", (void *) &targetuid );
    printf("targetuid size: %d bytes\n\n", sizeof(targetuid));

    printf("pw1 addr: %p\n", (void *) &pw1 );
    printf("pw1 size: %d bytes\n\n", sizeof(pw1));

    printf("hash1 addr: %p\n", (void *) &hash1 );
    printf("hash1 size: %d bytes\n\n", sizeof(hash1));

    printf("hash1hex addr: %p\n", (void *) &hash1hex );
    printf("hash1hex size: %d bytes\n\n", sizeof(hash1hex));

    printf("target1 addr: %p\n", (void *) &target1 );
    printf("target1 size: %d bytes\n\n", sizeof(target1));

    printf("hash2 addr: %p\n", (void *) &hash2 );
    printf("hash2 size: %d bytes\n\n", sizeof(hash2));

    printf("hash2hex addr: %p\n", (void *) &hash2hex );
    printf("hash2hex size: %d bytes\n\n", sizeof(hash2hex));

    printf("target2 addr: %p\n", (void *) &target2 );
    printf("target2 size: %d bytes\n\n", sizeof(target2));

    printf("hash3 addr: %p\n", (void *) &hash3 );
    printf("hash3 size: %d bytes\n\n", sizeof(hash3));

    printf("hash3hex addr: %p\n", (void *) &hash3hex );
    printf("hash3hex size: %d bytes\n\n", sizeof(hash3hex));

    printf("target3 addr: %p\n", (void *) &target3 );
    printf("target3 size: %d bytes\n\n", sizeof(target3));

    printf("pw2 addr: %p\n", (void *) &pw2 );
    printf("pw2 size: %d bytes\n\n", sizeof(pw2));

    printf("pw3 addr: %p\n", (void *) &pw3 );
    printf("pw3 size: %d bytes\n\n", sizeof(pw3));

    printf("hash_ptr addr: %p\n", (void *) &hash_ptr );
    printf("hash_ptr size: %d bytes\n\n", sizeof(hash_ptr));


    printf("userid: ");
    fgets(buffer, 1024, stdin);
    printf("buffer: ");
    //for (i=0; i < 32; i++)
    //    printf("%02hhx", buffer[i]);
    //printf("\n");
    strcpy(userid,buffer);

    printf("password1: ");
    fgets(buffer, 1024, stdin);
    //printf("buffer: ");
    //for (i=0; i < 32; i++)
    //    printf("%02hhx", buffer[i]);
    //printf("\n");
    strcpy(pw1,buffer);
//    i=123;
//    printf("i addr: %p\n",(void *) &i);
//    printf("i contents: %08x\n", i);
//    long *ptr= (long *) buffer;
//    for (i=0; i<8; i++){
//      printf("address %p is %08x\n",
//                 (void *) (ptr+i),
//                 (unsigned int) (*(ptr+i)));
//    }
    printf("password2: ");
    fgets(buffer, 1024, stdin);
    //printf("buffer: ");
    //for (i=0; i < 32; i++)
    //    printf("%02hhx", buffer[i]);
    //printf("\n");
    strcpy(pw2,buffer);

    printf("password3: ");
    fgets(buffer, 1024, stdin);
    //printf("buffer: ");
    //for (i=0; i < 32; i++)
    //    printf("%02hhx", buffer[i]);
    //printf("\n");
    strcpy(pw3,buffer);

    length = strlen(pw1)-1;
    if (length>16)
        length=16;
    SHA256(pw1, length, hash1);
    i = 0;
//    printf("pw1: ");
//    for (i=0; i < 16; i++)
//        printf("%02hhx", pw1[i]);
//    printf("\n");
//    printf("hash1: ");
//    for (i=0; i < 32; i++)
//        printf("%02hhx", hash1[i]);
//    printf("\n");
    hash_ptr = hash1hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash1[i]);
    }
    hash1hex[64]=0;
    //printf("target1: %s\n", target1);
    //printf("hash1hex:  %s\n",hash1hex);

    length = strlen(pw2)-1;
    if (length>16)
        length=16;
    SHA256(pw2, length, hash2);
    i = 0;
//    printf("hash2: ");
//    for (i=0; i < 32; i++)
//        printf("%02hhx", hash2[i]);
//    printf("\n");
    hash_ptr = hash2hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash2[i]);
    }
    hash2hex[64]=0;

    length = strlen(pw3)-1;
    if (length>16)
        length=16;
    SHA256(pw3, length, hash3);
    i = 0;
//    printf("hash3: ");
//    for (i=0; i < 32; i++)
//        printf("%02hhx", hash3[i]);
//    printf("\n");
    hash_ptr = hash3hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash3[i]);
    }
    hash3hex[64]=0;

    if (strncmp(userid, hash_ptr,16)==0 &&
        strncmp(target1, hash1hex, 64)==0 &&
        strncmp(target2, hash2hex, 64)==0 &&
        strncmp(target3, hash3hex, 64)==0) {
        printf("starting shell\n");
        freopen("/dev/tty", "r", stdin);
        execve("/bin/sh", NULL, NULL);
    }
    else
        printf("authentication failed.\n");
}
