start 2000
mover a,m
movm c,n
loop: add c,='5'
mover b,='9'
mult c,m
movem b,n
ltorg
='5'
='9'
bc le loop
stop
m dc 10
n dc 4
end
