./asm_t champs/$1.s;
xxd ex.cor > file_mine;
xxd champs/$1.cor > file_origin;
opendiff file_mine file_origin