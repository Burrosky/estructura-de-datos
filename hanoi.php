<?php
function hanoiTrace(int $n, string $from, string $to, string $aux, int $depth = 0): void {
    $pad = str_repeat('  ', $depth); 

    echo $pad . ">> Entrando: Hanoi($n, $from → $to, aux=$aux)\n";

    if ($n === 1) {
        echo $pad . "   Caso base: mover disco 1 de $from → $to\n";
        echo $pad . "<< Saliendo: Hanoi($n, $from → $to, aux=$aux)\n";
        return;
    }

    // Paso 1: mover n-1 discos de 'from' a 'aux'
    hanoiTrace($n - 1, $from, $aux, $to, $depth + 1);

    // Paso 2: mover el disco n
    echo $pad . "   Mover disco $n: $from → $to\n";

    // Paso 3: mover n-1 discos de 'aux' a 'to'
    hanoiTrace($n - 1, $aux, $to, $from, $depth + 1);

    echo $pad . "<< Saliendo: Hanoi($n, $from → $to, aux=$aux)\n";
}


echo "\n=== Demo con n = 3 ===\n";
hanoiTrace(3, 'A', 'B', 'C');
