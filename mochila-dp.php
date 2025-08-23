<?php
$pesos = [2, 3, 4];
$valores = [3, 4, 5];
$capacidad = 5;
$n = count($pesos);


$dp = array_fill(0, $n+1, array_fill(0, $capacidad+1, 0));

echo "Matriz inicial (todo ceros):\n";
print_r($dp);


for ($i = 1; $i <= $n; $i++) {
    for ($w = 0; $w <= $capacidad; $w++) {
        if ($pesos[$i-1] <= $w) {
           
            $sin_tomar = $dp[$i-1][$w];
           
            $tomar = $valores[$i-1] + $dp[$i-1][$w - $pesos[$i-1]];
         
            $dp[$i][$w] = max($sin_tomar, $tomar);
        } else {
           
            $dp[$i][$w] = $dp[$i-1][$w];
        }
    }

    echo "\nDespués de procesar el objeto $i (peso={$pesos[$i-1]}, valor={$valores[$i-1]}):\n";
    print_r($dp);
}

echo "\nBeneficio máximo: " . $dp[$n][$capacidad] . "\n";
