;=============================================================;
;           errno.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ERRNO_INC
#Define ERRNO_INC

#Define EPERM                               1
#Define ENOENT                              2
#Define ESRCH                               3
#Define EINTR                               4
#Define EIO                                 5
#Define ENXIO                               6
#Define E2BIG                               7
#Define ENOEXEC                             8
#Define EBADF                               9
#Define ECHILD                              10
#Define EAGAIN                              11
#Define ENOMEM                              12
#Define EACCES                              13
#Define EFAULT                              14
#Define EBUSY                               16
#Define EEXIST                              17
#Define EXDEV                               18
#Define ENODEV                              19
#Define ENOTDIR                             20
#Define EISDIR                              21
#Define EINVAL                              22
#Define ENFILE                              23
#Define EMFILE                              24
#Define ENOTTY                              25
#Define EFBIG                               27
#Define ENOSPC                              28
#Define ESPIPE                              29
#Define EROFS                               30
#Define EMLINK                              31
#Define EPIPE                               32
#Define EDOM                                33
#Define ERANGE                              34
#Define EDEADLK                             36
#Define ENAMETOOLONG                        38
#Define ENOLCK                              39
#Define ENOSYS                              40
#Define ENOTEMPTY                           41
#Define EILSEQ                              42

#Define EDEADLOCK                           EDEADLK

#ENDIF ;ERRNO_INC
