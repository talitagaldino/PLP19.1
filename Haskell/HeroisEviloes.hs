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

menuVisualizaBaralho :: [Carta.Carta] -> [Carta.Carta] -> IO()
menuVisualizaBaralho listaHerois listaViloes = do
  putStrLn("\nVocê deseja visualizar qual baralho: \n1) Heróis \n2) Vilões")
  deck <- getLine
  if(deck == "1") then do 
    putStrLn(Carta.descricaoCarta (listaHerois !! 0))
    putStrLn(Carta.descricaoCarta (listaHerois !! 1))
    putStrLn(Carta.descricaoCarta (listaHerois !! 2))
    putStrLn(Carta.descricaoCarta (listaHerois !! 3))
    putStrLn(Carta.descricaoCarta (listaHerois !! 4))
    putStrLn(Carta.descricaoCarta (listaHerois !! 5))
    putStrLn(Carta.descricaoCarta (listaHerois !! 6))
    putStrLn(Carta.descricaoCarta (listaHerois !! 7))
    putStrLn(Carta.descricaoCarta (listaHerois !! 8))
    putStrLn(Carta.descricaoCarta (listaHerois !! 9))
    putStrLn(Carta.descricaoCarta (listaHerois !! 10))
    putStrLn(Carta.descricaoCarta (listaHerois !! 11))
    putStrLn(Carta.descricaoCarta (listaHerois !! 12))
    putStrLn(Carta.descricaoCarta (listaHerois !! 13))
    putStrLn(Carta.descricaoCarta (listaHerois !! 14))
    menuInicial
    
  else if(deck == "2") then do
    putStrLn(Carta.descricaoCarta (listaViloes !! 0))
    putStrLn(Carta.descricaoCarta (listaViloes !! 1))
    putStrLn(Carta.descricaoCarta (listaViloes !! 2))
    putStrLn(Carta.descricaoCarta (listaViloes !! 3))
    putStrLn(Carta.descricaoCarta (listaViloes !! 4))
    putStrLn(Carta.descricaoCarta (listaViloes !! 5))
    putStrLn(Carta.descricaoCarta (listaViloes !! 6))
    putStrLn(Carta.descricaoCarta (listaViloes !! 7))
    putStrLn(Carta.descricaoCarta (listaViloes !! 8))
    putStrLn(Carta.descricaoCarta (listaViloes !! 9))
    putStrLn(Carta.descricaoCarta (listaViloes !! 10))
    putStrLn(Carta.descricaoCarta (listaViloes !! 11))
    putStrLn(Carta.descricaoCarta (listaViloes !! 12))
    putStrLn(Carta.descricaoCarta (listaViloes !! 13))
    putStrLn(Carta.descricaoCarta (listaViloes !! 14))
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
        let cartaBatalha = deckViloes !! 0
        Auxiliar.escolheCarta deckHerois cartaBatalha
      else if( baralho == "2") then do
        let cartaBatalha = deckHerois !! 0
        Auxiliar.escolheCarta deckViloes cartaBatalha
      else do
        putStrLn("Entrada invalida.")
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

