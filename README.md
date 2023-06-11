<h1>Heap Em C</h1>
Uma implementação de heap (com alocação dinâmica) na linguagem C.</br>

<h2>Structs</h2>
<ul>
<li><i><code>struct heap_struct</code></i></li>
Referida, por meio de <code>typedef</code>, como <code>heap</code>, armazena a estrutura do heap. Possui como valores:
  <ul>
    <li><code>int size</code>: tamanho total do heap (do vetor de conteúdo do heap)</li>
    <li><code>int taken</code>: tamanho já ocupado no heap. M.q. número de elementos.</li>
    <li><code>int type</code>: se é um maxheap (1) ou minheap (0).</li>
    <li><code>int *content</code>: vetor que armazena o conteúdo do heap.</li>
  </ul>
  Vale observar que <code>size</code>, <code>taken</code> e <code>content</code> são frequentemente atualizados pelas funções do arquivo header.
<hr/>
</ul>

<h2>Funções</h2>
<ul>
<li><i><code>hCreate</code></i> (int type, int initialSize)</li>
  Retorna um novo heap de tamanho inicial <code>initialSize</code>. Um heap pode ser criado com <code>heap nome = hCreate(tipoDoHeap, tamanho);</code> 
<hr/>

<li><i><code>hInsert</code></i> (heap *aHeap, int value)</code></li>
  Insere um valor no heap. Caso necessário, também redimensiona o tamanho do heap.content dinamicamente, com <code>realloc</code>, dobrando seu espaço.
<hr/>

<li><i><code>hPop</code></i> (heap *aHeap)</code></li>
  Remove a raiz do heap e retorna esse elemento.
<hr/>

<li><i><code>printHeap</code></i> (heap aHeap)</code></li>
  Imprime o heap em camadas, como uma árvore.
<hr/>

<li><i><code>printHeapArray</code></i> (heap aHeap)</code></li>
  Imprime o heap normalmente (como um vetor).
<hr/>

<li><i><code>heapHeight</code></i> (heap aHeap)</code></li>
  Retorna a altura do heap, como em uma árvore.
<hr/>

<li><i><code>hExists</code></i> (heap aHeap, int value)</code></li>
  Retorna 1 caso um elemento exista no heap. Caso contrário, retorna 0.
<hr/>
