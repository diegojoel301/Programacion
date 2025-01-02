import math as m
 
def sol():
    cad = input()
 
    if cad[len(cad) - 1] == " ":
        vin = cad[0:len(cad) - 2].split(" ")
    else:
        vin = cad[0:len(cad) - 1].split(" ")
 
    costo_total = float(vin[len(vin) - 1])
    precio_total = float(vin[0] + "")
 
    for i in range(1, len(vin) - 1):
        a = float(vin[i].split(",")[0])
        b = float(vin[i].split(",")[1])
        costo_total += a
        precio_total += b
    ganancia = abs(costo_total - precio_total)
    ans = m.floor((100 * ganancia) / precio_total)
    print(ans)
 
while True:
    try:
        sol()
    except EOFError:
        break