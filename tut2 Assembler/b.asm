start 2246
move n 
mover b,one
movem b, term
again : mult b , term
mover c,term
add c,one
movem c,term
comp c,n
bc le, again
movem b,result
stop
n ds 1
result ds 20
one dc 1
term ds 1
end
