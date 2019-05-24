import qualified Auxiliar as Auxiliar
import qualified Carta as Carta
import Control.Concurrent
import System.Console.ANSI
import System.Random.Shuffle


main :: IO()
main = do
  putStrLn (Auxiliar.exibeLetreiro)
  menuInicial

opcoesMenu :: String
opcoesMenu = "\nEscolha uma Opcão: \n1) Jogar \n2) Visualizar Baralhos \n3) Regras \n4) Sair"

visualizaDeck :: [Carta.Carta] -> IO()
visualizaDeck deck = do
    putStrLn(Carta.descricaoCarta (deck !! 0))
    putStrLn(Carta.descricaoCarta (deck !! 1))
    putStrLn(Carta.descricaoCarta (deck !! 2))
    putStrLn(Carta.descricaoCarta (deck !! 3))
    putStrLn(Carta.descricaoCarta (deck !! 4))
    putStrLn(Carta.descricaoCarta (deck !! 5))
    putStrLn(Carta.descricaoCarta (deck !! 6))
    putStrLn(Carta.descricaoCarta (deck !! 7))
    putStrLn(Carta.descricaoCarta (deck !! 8))
    putStrLn(Carta.descricaoCarta (deck !! 9))
    putStrLn(Carta.descricaoCarta (deck !! 10))
    putStrLn(Carta.descricaoCarta (deck !! 11))
    putStrLn(Carta.descricaoCarta (deck !! 12))
    putStrLn(Carta.descricaoCarta (deck !! 13))
    putStrLn(Carta.descricaoCarta (deck !! 14))


menuVisualizaBaralho :: [Carta.Carta] -> [Carta.Carta] -> IO()
menuVisualizaBaralho listaHerois listaViloes = do
  putStrLn("\nVocê deseja visualizar qual baralho: \n1) Heróis \n2) Vilões")
  deck <- getLine
  if(deck == "1") then do 
    visualizaDeck listaHerois
    menuInicial
    
  else if(deck == "2") then do
    visualizaDeck listaViloes
    menuInicial
  else do 
    putStrLn("Digite uma opção válida.")
    menuVisualizaBaralho listaHerois listaViloes

menuMostraRegras :: IO()
menuMostraRegras = do
  putStrLn("\nAs regras do jogo são as seguintes:")
  putStrLn("->O jogador e a máquina irão alternar turnos")
  putStrLn("->O jogador puxa aleatoriamente 3 cartas das 15 do seu baralho")
  putStrLn("->Escolhe 1 para colocar em combate")
  putStrLn("->O mesmo serve para a máquina")
  putStrLn("->As outras 2 nao escolhidas retornam ao deck")
  putStrLn("->Em cada turno escolhe um atributo para a batalha")
  putStrLn("->Marca 1 ponto quem tiver maior atributo")
  putStrLn("->Cartas especiais concederá o dobro de pontos para o vencedor do turno.")
  putStrLn("->As duas cartas que batalharam são removidas do jogo")
  putStrLn("->Quando acabarem as cartas quem tiver mais ponto vence o jogo.")
  putStrLn("")
  menuInicial


 

menuInicial :: IO()
menuInicial = do
    putStrLn(opcoesMenu)
    putStrLn("Digite aqui sua opção: ")
    opcao <- getLine

    if (opcao == "1") then do
      clearScreen
      let cartasHerois = Auxiliar.iniciarCartasHerois
      deckHerois <- shuffleM cartasHerois
      let cartaViloes = Auxiliar.iniciarCartasViloes
      deckViloes <- shuffleM cartaViloes
      putStrLn ("Você deseja jogar com:  \n1) Heróis \n2) Vilões")
      baralho <- getLine
      if (baralho == "1") then do
		--gameLoop deckHerois deckViloes 15
        --let cartaBatalha = deckViloes !! 0
        Auxiliar.escolheCarta deckHerois deckViloes 13 0 0
      else if( baralho == "2") then do
		--gameLoop deckViloes deckHerois 15
        --let cartaBatalha = deckHerois !! 0
        Auxiliar.escolheCarta deckViloes deckHerois 13 0 0
      else do
        putStrLn("Entrada Inválida.")
        menuInicial
        
    
      
    else if (opcao == "2") then do
      clearScreen
      let cartasHerois = Auxiliar.iniciarCartasHerois
      let cartaViloes = Auxiliar.iniciarCartasViloes
      menuVisualizaBaralho cartasHerois cartaViloes

    else if (opcao == "3") then do
      clearScreen
      menuMostraRegras

    else if (opcao == "4") then clearScreen
        else menuInicial
