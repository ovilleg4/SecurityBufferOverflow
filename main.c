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


    printf("i address: %p\n", (void *) &i );
    printf("length address: %p\n", (void *) &length );
    long *ptr = (long *) buffer;
    for(i=0;i<128;i++)
      printf("address %p is %08x\n",(void *) (ptr+i), (unsigned int) (*(ptr+i)) );
    printf("%p\n",(void *) ptr);
    ptr = (long *) userid;
    for(i=0;i<2;i++)
      printf("address %p is %08x\n",(void *) (ptr+i), (unsigned int) (*(ptr+i)) );
    printf("%p\n",(void *) ptr);
    //printf("buffer address: %p\n", (void *) &buffer);
    //ptr = (long *) userid;
    //printf("userid address: %p\n", (void *) &userid);
    //ptr = (long *) targetuid;
    //printf("targetuid address: %p\n", (void *) &targetuid);
    //ptr = (long *) pw1;
    //printf("pw1 address: %p\n", (void *) &pw1);
    //ptr = (long *) hash1;
    //printf("hash1 address: %p\n", (void *) &hash1);
    //ptr = (long *) hash1hex;
    //printf("hash1hex address: %p\n", (void *) &hash1hex);
    //ptr = (long *) target1;
    //printf("target1 address: %p\n", (void *) &target1);
    //ptr = (long *) hash2;
    //printf("hash2 address: %p\n", (void *) &hash2);
    //ptr = (long *) hash2hex;
    //printf("hash2hex address: %p\n", (void *) &hash2hex);
    //ptr = (long *) target2;
    //printf("target2 address: %p\n", (void *) &target2);
    //ptr = (long *) hash3;
    //printf("hash3 address: %p\n", (void *) &hash3);
    //ptr = (long *) hash3hex;
    //printf("hash3hex address: %p\n", (void *) &hash3hex);
    //ptr = (long *) target3;
    //printf("target3 address: %p\n", (void *) &target3);
    //ptr = (long *) pw2;
    //printf("pw2 address: %p\n", (void *) &pw2);
    //ptr = (long *) pw3;
    //printf("pw3 address: %p\n", (void *) &pw3);


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

    if (strncmp(userid, targetuid,16)==0 &&
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
