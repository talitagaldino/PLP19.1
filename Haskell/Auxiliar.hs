module Auxiliar where
import qualified Carta as Carta
import System.IO.Unsafe(unsafeDupablePerformIO)
import System.Random
import Data.List.Split

exibeLetreiro :: String
exibeLetreiro = unsafeDupablePerformIO (readFile "letreiro.txt")

atributos :: String
atributos = "[VITALIDADE | INTELIGENCIA | FORCA | VELOCIDADE | HABILIDADE]"

leAtributo :: IO String
leAtributo = do
  atributo <- getLine
  if (verificaAtributo atributo) then return atributo else leAtributo
  
escolheAtributo :: Carta.Carta -> String
escolheAtributo carta = do
  let vit = Carta.vitalidade carta
  let int = Carta.inteligencia carta
  let for = Carta.forcaBruta carta
  let vel = Carta.velocidade carta
  let hab = Carta.habilidade carta

  escolherAtributoAuxiliar vit int for vel hab
  
escolherAtributoAuxiliar :: Int -> Int -> Int -> Int -> Int -> String
escolherAtributoAuxiliar vit int for vel hab 
  | vit >= max (max int for) (max vel hab ) = "VITALIDADE"
  | int >= max  for (max vel hab) = "INTELIGENCIA"
  | for >= max vel hab = "FORCA"
  | vel >= hab = "VELOCIDADE"
  | otherwise = "HABILIDADE"
  

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


--Funcao para imprimir uma lista recursivamente
--imprimeLista :: [Carta.Carta] -> String
   
mapeiaCarta :: Int -> [String] -> Carta.Carta
mapeiaCarta posicao lista =
  Carta.Carta{Carta.nome = (lista) !! 0, 
  Carta.vitalidade = read((lista) !! 1),
  Carta.inteligencia = read((lista) !! 2),
  Carta.forcaBruta = read((lista) !! 3),
  Carta.velocidade =  read((lista) !! 4),
  Carta.habilidade =  read((lista) !! 5),
  Carta.especial =  read((lista) !! 6)}