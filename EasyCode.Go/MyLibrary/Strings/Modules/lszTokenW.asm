.data
NextTokenW DD ?
LenTokenW DD ?

.code
lszTokenW FRAME pString,pToken
   uses edi,ebx,ecx

   mov eax,[pToken]
   movzx ebx,W[eax]

   mov edi,[pString]
   or edi,edi
   jz >
      mov [NextTokenW],edi
      invoke lszLenW,edi
      mov [LenTokenW],eax
      jmp >L1
   :
      mov edi,[NextTokenW]
   L1:

   mov ecx,[LenTokenW]
   mov ax,bx
   repne scasw

   cmp [edi-2],al
   jne >
      mov W[edi-2],0
   :
   mov eax,[NextTokenW]
   mov [NextTokenW],edi
   mov [LenTokenW],ecx
   RET
ENDF
