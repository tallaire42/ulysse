# Conditionnal jump

## Exemple d'utilisation

```

cmp rax, 23
je _doThis

```

## Jump symbols (signed) :

- je	a = b
- jne	a != b
- jg	a > b
- jge	a >= b
- jl	a < b
- jle	a <= b
- jz	a = 0
- jnz	a != 0
- jo	overfow occured
- jno	overflow dit not occured

## Jump symbols (unsigned) :

- ja	a > b
- jae	a >= b
- je	a < b
- jbe	a <= b
