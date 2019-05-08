import qualified Auxiliar as Auxiliar
import qualified Pilha as Pilha
import qualified Carta as Carta


--Main para rodar o codigo, inicia aqui o fluxo do codigo.
main :: IO()
main = do
  putStrLn ("HEROIS E VILOES - SUPER TRUNFO")
  menuInicial

--Menu das opcoes que tem no programa
opcoesMenu :: String
opcoesMenu = "Escolha uma Opcão: \n1) Jogar \n2) Visualizar Baralhos \n3) Regras \n4) Sair"
  
--Menu inicial para rodar a logica do programa, comeca aqui a logica do programa.
menuInicial :: IO()
menuInicial = do
  --Eu comecei bem procedural passando as opcoesMenu criado anteriomente
    putStrLn(opcoesMenu)
    putStrLn("Digite aqui sua opcao:")
    opcao <- getLine
    -- Aqui eh a opcao Jogar e comeca a logica procedural para criar as cartas para jogar
    if opcao == "1" then do
      clearScreen
      --inicializa as cartas dos herois, lendo o txt dos herois
      let cartasHerois = Auxiliar.iniciarCartasHerois
      --Embaralha essas cartas
      deckHerois <- shuffleM cartasHerois 
      --Inicializa as cartas dos viloes, lendo do txt dos viloes
      let cartaViloes = Auxiliar.iniciarCartasViloes
      --Embaralha essas cartas
      deckViloes <- shuffleM cartaViloes
      
      --Aqui cria uma lista com 15 cartas de herois
      let lista_herois = take 15 deckHerois
      --Aqui cria uma lista com 15 cartas de viloes
      let lista_viloes = take 15 deckViloes
      --Inicia uma pilha de cartas de herois(fazemos isso para podermos controlar melhor a remocao das cartas)
      let pilha_herois = Auxiliar.iniciarPilha lista_herois
      --Inicia uma pilha de cartas de viloes.
      let pilha_viloes = Auxiliar.iniciarPilha lista_viloes

      --Continua fazendo a logica procedural...
      
      --Precisamos criar essa funcao para controlar o loop da jogada, tipo o gameLoop em C++
      --gameLoop atributo pilha_herois pilha_viloes 1
      
    
    else if opcao == "2" then do
      --Funcao para mostrar os decks pre estabelecidos no jogo
      --visualizarBaralho deckEscolhido

    --Mostra as regras do jogo  
    else if opcao == "3" then do
      putStrLn("\nAs regras do jogo sao as seguintes:")
      putStrLn("->O jogador e a máquina irão alternar turnos")
      putStrLn("->O jogador puxa aleatoriamente 3 cartas das 15 do seu baralho")
      putStrLn("->Escolhe 1 para colocar em combate")
      putStrLn("->O mesmo serve para a máquina")
      putStrLn("->As outras 2 nao escolhidas retornam ao deck")
      putStrLn("->Em cada turno escolhe um atributo para a batalha")
      putStrLn("->Marca 1 ponto quem tiver maior atributo")
      putStrLn("->As duas cartas que batalharam são removidas do jogo")
      putStrLn("->Quando acabarem as cartas quem tiver mais ponto vence o jogo.")
      putStrLn("")
      menuInicial

    --Sai do jogo, na vdd finaliza o programa e limpa tela.
    else if opcao == "4" then clearScreen
        else
            menuInicial


--Aqui eh a funcao principal do programa, contendo a logica do loop para jogar.
gameLoop :: Int -> Pilha.Stack Carta.Carta -> Pilha.Stack Carta.Carta -> Int -> IO()

--Esse metodo seria para controlar a remocao das cartas do jogo na hora da batalha 
ganhaCarta :: Carta.Carta -> Pilha.Stack Carta.Carta -> Pilha.Stack Carta.Carta
ganhaCarta carta pilha = do
  --Aqui ele cria uma tupla de uma carta removida e uma pilha e isso eh atribuido a carta removida da pilha principal
  let (carta_removida,pilha_temp1) = Pilha.pop pilha
  --Depois cria uma pilha temporaria para poder inverter a pilha temp criada antes
  let pilha_temp2 = Pilha.invertePilha pilha_temp1
  --Nesse ponto coloca a carta removida na pilha temporaria criada anteriormente
  let pilha_temp3 = Pilha.push carta_removida pilha_temp2
  --Aqui coloca a carta passada como argumento na pilha temp criada anteriormente
  let pilha_temp4 = Pilha.push carta pilha_temp3
  --Por fim, inverte a ultima pilha temporaria ja com as cartas removidas, assim podendo seguir o fluxo e nao ter mais a carta escolhida para jogar.
  Pilha.invertePilha pilha_temp4