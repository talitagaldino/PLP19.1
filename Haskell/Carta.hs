module Carta where

--Precisamos colocar os atributos das cartas.

--Esse metodo eh tipo o toString das classes em Java, que retorna um formato em String da Classe.                          
descricaoCarta:: Carta -> String



--metodo para verificar se o atributo super eh true                                                
ehSuper :: Carta -> Bool


--Ver como sera o metodo de desempate
desempata :: Carta -> Carta -> Int


--Metodo para comparar os atributos das 2 cartas na batalha
compara :: String -> Carta -> Carta -> Int
