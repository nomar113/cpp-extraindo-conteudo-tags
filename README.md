<h1>Extraindo conteúdo entre tags</h1> <br>
<br>
<span>Para criar o executável:<b>make stackProblem </b></span> <br>
<span>Para inserir a entrada:<b>./stackProblem < input </b></span> <br>
<span>Para inserir a entrada e testar com a saída:<b>./stackProblem < input | diff - output </b></span> <br>
<br>
Em uma linguagem baseada em tags, como XML ou HTML, o conteudo é envolto entre uma tag de
abertura e sua correspondente tag de fechamento, por exemplo <tag> e </tag>. Toda a tag de
fechamento começa com /. Toda tag de abertura deve ter sua correspondente de fechamento e vice-
versa. <br>
Dado um texto em uma linguagem baseada em tags, escreva uma função que extraia o conteudo de
um conjunto bem definido de tags, obedecendo aos seguintes critérios: <br><br>

Os nomes das tags de entrada e saida devem ser os mesmos. O codigo html ```<h1>Hello
World</h2>``` não é valido pois a tag de saida não é igual à de entrada.
Tags podem ser aninhadas, mas o conteudo entre tags aninhadas não é considerado valido.
Por exemplo, em <a>conteudos</a>invalidos</h1> conteudos é valido mas invalidos não.
Tags podem consistir de qualquer conjunto de caracteres imprimiveis, desde que da língua
portuguesa.
O tamanho do texto deve ser de, pelo menos, 15 caracteres e não maior que 100.000. <br>
<br>
Entrada:<br>
```<h1>Nayeem loves counseling</h1>```<br>
```<h1><h1>Sanjay has no watch</h1></h1><par>So wait for a while</par>```<br>
```<Amee>safat codes like a ninja</amee>```<br>
```<SA premium>Imtiaz has a secret crush</SA premium>```<br>
<br>
Saída:<br>
Nayeem loves counseling<br>
Sanjay has no watch<br>
So wait for a while<br>
None<br>
Imtiaz has a secret crush<br>
