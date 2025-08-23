<?php
function mochilaSimple($pesos, $valores, $capacidad) {
    $n = count($pesos);
    $mejor_valor = 0;
    $mejor_combinacion = [];

   
    $combinaciones = [[]];
    for ($i = 0; $i < $n; $i++) {
        echo "$i \n ";
        $nuevas = [];
        foreach ($combinaciones as $comb) {
            
            $nuevas[] = array_merge($comb, [$i]); 
        
            
        }
        $combinaciones = array_merge($combinaciones, $nuevas);
    
         print_r($combinaciones);
        
    }

   
    foreach ($combinaciones as $comb) {
        $peso_total = 0;
        $valor_total = 0;
        foreach ($comb as $obj) {
            $peso_total  += $pesos[$obj];
            $valor_total += $valores[$obj];
        }
        if ($peso_total <= $capacidad && $valor_total > $mejor_valor) {
            $mejor_valor = $valor_total;
            $mejor_combinacion = $comb;
        }
    }

    return [
        "mejor_valor" => $mejor_valor,
        "mejor_combinacion" => $mejor_combinacion
    ];
}

$pesos = [3, 4, 5];
$valores = [30, 50, 60];
$capacidad = 8;

$resultado = mochilaSimple($pesos, $valores, $capacidad);

echo "Beneficio máximo: {$resultado['mejor_valor']}\n";
echo "Objetos elegidos: " . implode(", ", $resultado['mejor_combinacion']) . "\n";
?>
