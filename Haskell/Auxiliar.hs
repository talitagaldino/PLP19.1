module Auxiliar where
import qualified Carta as Carta
import qualified Pilha as Pilha


atributos :: String
atributos = "[VITALIDADE | INTELIGENCIA | FORCA_BRUTA | VELOCIDADE | HABILIDADE]"

leAtributo :: IO String

  
escolheAtributo :: Carta.Carta -> String

  
escolherAtributoAuxiliar :: Int -> Int -> Int -> Int -> Int -> String


verificaAtributo :: String -> Bool


iniciarPilha :: [Carta.Carta] -> Pilha.Stack Carta.Carta


iniciarPilhaAuxiliar :: [Carta.Carta] -> Pilha.Stack Carta.Carta -> Pilha.Stack Carta.Carta


iniciarCartasHerois :: [Carta.Carta]


iniciarCartasViloes :: [Carta.Carta]


   
mapeiaCarta :: Int -> [String] -> Carta.Carta
