module Carta where

  data Carta = Carta {nome :: String, vitalidade :: Int, inteligencia :: Int, forcaBruta :: Int, velocidade :: Int, habilidade :: Int, especial :: Bool
                           } deriving (Show)  
                            
  descricaoCarta:: Carta -> String
  descricaoCarta (Carta {nome = nom, vitalidade = vit,
  inteligencia = int, forcaBruta = for, velocidade = vel, habilidade = hab, especial = esp}) = 
                                                  "Nome: " ++ nom ++ "\n" ++
                                                  "Vitalidade: " ++ show(vit) ++ "\n" ++
                                                  "Inteligencia: " ++ show(int) ++ "\n" ++
                                                  "Forca: " ++ show(for) ++ "\n" ++
                                                  "Velocidade: " ++ show(vel) ++ "\n" ++
                                                  "Habilidade: " ++  show(hab) ++ "\n" ++
                                                  if esp then "CARTA ESPECIAL\n" else ""
  
  
                                                  
  ehSuper :: Carta -> Bool
  ehSuper carta = ehSuper carta
  
  --Ver como sera o metodo de desempate
  desempata :: Carta -> Carta -> Int
  desempata carta1 carta2 = if (especial carta1) < (especial carta2) then 1 else -1 
  
  
  compara :: String -> Carta -> Carta -> Int
  compara atributo carta1 carta2 
    | (atributo) == "VITALIDADE" && (vitalidade1 - vitalidade2) > 0 = 1
    | (atributo) == "VITALIDADE" && (vitalidade1 - vitalidade2) < 0 = -1
    | (atributo) == "VITALIDADE" && (vitalidade1 - vitalidade2) == 0 = desempata carta1 carta2
    | (atributo) == "INTELIGENCIA" && (inteligencia1 - inteligencia2) > 0 = 1
    | (atributo) == "INTELIGENCIA" && (inteligencia1 - inteligencia2) < 0 = -1
    | (atributo) == "INTELIGENCIA" && (inteligencia1 - inteligencia2) == 0 = desempata carta1 carta2
    | (atributo) == "FORCA" && (forcaBruta1 - forcaBruta2) > 0 = 1
    | (atributo) == "FORCA" && (forcaBruta1 - forcaBruta2) < 0 = -1
    | (atributo) == "FORCA" && (forcaBruta1 - forcaBruta2) == 0 = desempata carta1 carta2
    | (atributo) == "VELOCIDADE" && (velocidade1 - velocidade2) > 0 = 1
    | (atributo) == "VELOCIDADE" && (velocidade1 - velocidade2) < 0 = -1
    | (atributo) == "VELOCIDADE" && (velocidade1 - velocidade2) == 0 = desempata carta1 carta2
    | (atributo) == "HABILIDADE" && (habilidade1 - habilidade2) > 0 = 1
    | (atributo) == "HABILIDADE" && (habilidade1 - habilidade2) < 0 = -1
    | (atributo) == "HABILIDADE" && (habilidade1 - habilidade2) == 0 = desempata carta1 carta2
    where (vitalidade1,vitalidade2, inteligencia1,inteligencia2, forcaBruta1,forcaBruta2, velocidade1,velocidade2,habilidade1,habilidade2) = ((vitalidade carta1), (vitalidade carta2),(inteligencia carta1),(inteligencia carta2),(forcaBruta carta1),(forcaBruta carta2),(velocidade carta1),(velocidade carta2),(habilidade carta1),(habilidade carta2))  