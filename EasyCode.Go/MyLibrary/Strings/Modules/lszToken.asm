.data
NextToken DD ?
LenToken DD ?

.code
lszToken FRAME pString,pToken
   uses edi,ebx,ecx

   mov eax,[pToken]
   movzx ebx,B[eax]

   mov edi,[pString]
   or edi,edi
   jz >
      mov [NextToken],edi
      invoke lszLen,edi
      mov [LenToken],eax
      jmp >L1
   :
      mov edi,[NextToken]
   L1:
   mov ecx,[LenToken]
   mov al,bl
   repne scasb

   cmp [edi-1],al
   jne >
      mov B[edi-1],0
   :
   mov eax,[NextToken]
   mov [NextToken],edi
   mov [LenToken],ecx
   RET
ENDF
