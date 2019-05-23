module Auxiliar where
import qualified Carta as Carta
import System.IO.Unsafe(unsafeDupablePerformIO)
import System.Random
import Data.List.Split

removeCarta lista item = [g | g <- lista, g/= item ]

exibeLetreiro :: String
exibeLetreiro = unsafeDupablePerformIO (readFile "letreiro.txt")

atributos :: String
atributos = "VITALIDADE | INTELIGENCIA | FORCA | VELOCIDADE | HABILIDADE"

leAtributo :: IO String
leAtributo = do
  atributo <- getLine
  if (verificaAtributo atributo) then return atributo else leAtributo
  

escolheCarta :: [Carta.Carta] -> [Carta.Carta] -> Int -> Int -> Int -> IO()
escolheCarta _ _ 0 pontos1 pontos2 
  | pontos1 > pontos2 = putStrLn("Jogador 1 Venceu")
  | pontos1 < pontos2 = putStrLn("Máquina")
  | otherwise = putStrLn("Empate")
escolheCarta deck deck2 rodadas pontos1 pontos2 = do
  let cartaBatalha = deck2 !! 0
  let carta1 = deck !! 0
  let carta2 = deck !! 1
  let carta3 = deck !! 2

      
  putStrLn("Primeira Carta\n" ++ Carta.descricaoCarta(carta1))
  putStrLn("Segunda Carta\n" ++ Carta.descricaoCarta(carta2))
  putStrLn("Terceira Carta\n" ++ Carta.descricaoCarta(carta3))

  putStrLn("Deseja batalhar com qual carta: \n1) Primeira Carta\n2) Segunda Carta\n3) Terceira Carta" )

  escolha <- getLine
  if (escolha == "1") then do
    putStrLn("\nA carta escolhida foi: \n" ++ Carta.descricaoCarta(carta1))
    putStrLn("\nTurnos restantes: \n" ++ show rodadas)
    putStrLn("Agora digite seu atributo para batalha: " ++ Auxiliar.atributos)
    atributo <- Auxiliar.leAtributo
    let comparador = Carta.compara atributo carta1 cartaBatalha
    if (comparador == 1) then do
      putStrLn ("")
      putStrLn ("CARTA MÁQUINA")
      putStrLn(Carta.descricaoCarta (cartaBatalha))
      putStrLn ("VOCE VENCEU O TURNO")
      escolheCarta (removeCarta deck carta1) (removeCarta deck2 cartaBatalha) (rodadas - 1) (pontos1 + 1) pontos2
    
    else do
      putStrLn ("")
      putStrLn ("CARTA MÁQUINA")
      putStrLn(Carta.descricaoCarta (cartaBatalha))
      putStrLn ("MÁQUINA VENCEU O TURNO")
      escolheCarta (removeCarta deck carta1) (removeCarta deck2 cartaBatalha) (rodadas - 1) pontos1 (pontos2 + 1) 
      

    else if (escolha == "2") then do
        putStrLn("\nA carta escolhida foi: \n" ++ Carta.descricaoCarta(carta2))
        putStrLn("Agora digite seu atributo para batalha: " ++ Auxiliar.atributos)
        atributo <- Auxiliar.leAtributo
        let comparador = Carta.compara atributo carta2 cartaBatalha
        if (comparador == 1) then do
          putStrLn ("")
          putStrLn ("CARTA MÁQUINA")
          putStrLn(Carta.descricaoCarta (cartaBatalha))
          putStrLn ("VOCE VENCEU O TURNO")
          escolheCarta (removeCarta deck carta2) (removeCarta deck2 cartaBatalha) (rodadas - 1) (pontos1 + 1) pontos2
        
        else do
          putStrLn ("")
          putStrLn ("CARTA MÁQUINA")
          putStrLn(Carta.descricaoCarta (cartaBatalha))
          putStrLn ("MÁQUINA VENCEU O TURNO")
          escolheCarta (removeCarta deck carta2) (removeCarta deck2 cartaBatalha) (rodadas - 1) pontos1 (pontos2 + 1)

    else if (escolha == "3") then do
    putStrLn("\nA carta escolhida foi: \n" ++ Carta.descricaoCarta(carta3))
    putStrLn("Agora digite seu atributo para batalha: " ++ Auxiliar.atributos)
    atributo <- Auxiliar.leAtributo
    let comparador = Carta.compara atributo carta3 cartaBatalha
    if (comparador == 1) then do
      putStrLn ("")
      putStrLn ("CARTA MÁQUINA")
      putStrLn(Carta.descricaoCarta (cartaBatalha))
      putStrLn ("VOCE VENCEU O TURNO")
      escolheCarta (removeCarta deck carta3) (removeCarta deck2 cartaBatalha) (rodadas - 1) (pontos1 + 1) pontos2
    
    else do
      putStrLn ("")
      putStrLn ("CARTA MÁQUINA")
      putStrLn(Carta.descricaoCarta (cartaBatalha))
      putStrLn ("MÁQUINA VENCEU O TURNO")
      escolheCarta (removeCarta deck carta3) (removeCarta deck2 cartaBatalha) (rodadas - 1) pontos1 (pontos2 + 1)

  else do putStrLn("Entrada Inválida")


verificaAtributo :: String -> Bool
verificaAtributo atributo 
  | atributo == "VITALIDADE" = True
  | atributo == "INTELIGENCIA" = True
  | atributo == "FORCA" = True
  | atributo == "VELOCIDADE" = True
  | atributo == "HABILIDADE" = True
  | otherwise = False


iniciarCartasHerois :: [Carta.Carta]
iniciarCartasHerois = do
    let arquivo = unsafeDupablePerformIO (readFile "herois.txt")
    let lista =  ((map ( splitOn ",") (lines arquivo))) 
    let lista_cartas = ((map (mapeiaCarta 0)) (lista))
    return lista_cartas !! 0 

iniciarCartasViloes :: [Carta.Carta]
iniciarCartasViloes = do
    let arquivo = unsafeDupablePerformIO (readFile "viloes.txt")
    let lista =  ((map ( splitOn ",") (lines arquivo))) 
    let lista_cartas = ((map (mapeiaCarta 0)) (lista))
    return lista_cartas !! 0 

   
mapeiaCarta :: Int -> [String] -> Carta.Carta
mapeiaCarta posicao lista =
  Carta.Carta{Carta.nome = (lista) !! 0, 
  Carta.vitalidade = read((lista) !! 1),
  Carta.inteligencia = read((lista) !! 2),
  Carta.forcaBruta = read((lista) !! 3),
  Carta.velocidade =  read((lista) !! 4),
  Carta.habilidade =  read((lista) !! 5),
  Carta.especial =  read((lista) !! 6)}
