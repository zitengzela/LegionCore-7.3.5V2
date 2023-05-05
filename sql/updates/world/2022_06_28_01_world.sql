
DELETE FROM `playercreateinfo` WHERE (`race`=5 AND (`class` IN (1, 3, 4, 5, 8, 9, 10)));

INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(5, 1, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 3, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 4, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 5, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 8, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 9, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82),
(5, 10, 0, 5692, 1704.2299565859375, 1704.26799959375, 134.1266877744140625, 29.82);

DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (24971, 24970, 24973, 26802, 28672, 24961, 28651, 26801, 26800, 25089, 24960, 28652, 26799, 28608, 24959) AND `Locale` IN ('esES', 'esMX');

INSERT INTO `quest_offer_reward_locale` (`ID`, `Locale`, `OfferRewardText`, `VerifiedBuild`) VALUES
(24971, 'esES', 'Volver a nacer bajo el poder de una Val\'kyr es un proceso traumático. Muchos no sobreviven a la impresión y se convierten en zombis o necrófagos.$b$bOtros conservan justo la humanidad necesaria para parecer normales por fuera... pero están enfermos por dentro. Deberíamos haber matado a esos Pudrecerebro el mismo día que los resucitaron.$b$bEn cuanto a ti... Tú eres $gun:una; $c muy fuerte, $n. Sabía que medrarías. Pronto abandonarás Camposanto.', 0),
(24970, 'esES', '$n, llegaste.$b$b¿Ves esas tiendas de ahí adelante? Allá es adonde vamos. Seguramente la batalla ya ha comenzado.', 0),
(24973, 'esES', 'Bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo la infestación. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n.', 0),
(26802, 'esES', 'Gracias, $n. Esta armadura te servirá de ayuda. $B$BEspero que, al menos, te dé más suerte que a su último portador...', 0),
(28672, 'esES', '¿Qué tenemos aquí? $gUn:Una; $c $gnovato y listo:novata y lista; para el combate, ¿eh?', 0),
(24961, 'esES', '¿Dices que salió corriendo? Qué pena.$B$BMuy bien. Mientras conserve su libre albedrío habrá esperanza.', 0),
(28651, 'esES', 'Que la Dama Oscura te proteja, $n.', 0),
(26801, 'esES', 'Tu fuerza crece por momentos, $n. No es la primera vez que veo individuos como tú. No tardarás en irte de Camposanto y acometer tareas más importantes. Pero nunca olvides dónde comenzaste.$b$bLlegarás muy lejos, $c.', 0),
(26800, 'esES', 'Buen trabajo, $n, sabía que no eras $gun:una; inútil.$b$bTen, quédate con uno de estos. Los guardias de la Muerte tienen montones enteros de estos trastos cogiendo polvo.', 0),
(25089, 'esES', 'Últimamente esas Val\'kyr no dan abasto resucitando a $glos novatos:las novatas; como tú. Esta mañana ya he visto varias docenas de cadáveres corriendo por estas colinas.$b$bPero tú eres $gel:la; $c más $gprometedor:prometedora; que he visto en lo que va de día.', 0),
(24960, 'esES', 'Has hecho bien, $c. Como puedes ver, no todos nos hemos resignado a nuestro destino. Me alegra ver que estás deseando trabajar, al menos.$b$bValdred será un recurso valioso para los Renegados. En cuanto a los otros dos... No hay mucho que podamos hacer. No podemos obligarlos a que se unan a nosotros.', 0),
(28652, 'esES', '¿Sí? ¿Y tú quién eres?', 0),
(26799, 'esES', 'Ni siquiera el poder de las Val\'kyr bastó para salvar a estas criaturas. Estaban condenadas desde el principio.$b$bTe conseguí algo de equipo, $n. No es mucho, pero te ayudará.', 0),
(28608, 'esES', 'Es exactamente lo que necesitaba. Vas a ser una gran baza para los Renegados, $n.$b$bSe rumorea que en tu vida anterior fuiste $gun:una; $c de renombre. A lo mejor debería asignarte una tarea más emocionante.', 0),
(24959, 'esES', 'Hola. Tú debes de ser... ¿$n?', 0),
(24971, 'esMX', 'Volver a nacer bajo el poder de una Val\'kyr es un proceso traumático. Muchos no sobreviven a la impresión y se convierten en zombis o necrófagos.$b$bOtros conservan justo la humanidad necesaria para parecer normales por fuera... pero están enfermos por dentro. Deberíamos haber matado a esos Pudrecerebro el mismo día que los resucitaron.$b$bEn cuanto a ti... Tú eres $gun:una; $c muy fuerte, $n. Sabía que medrarías. Pronto abandonarás Camposanto.', 0),
(24970, 'esMX', '$n, llegaste.$b$b¿Ves esas tiendas de ahí adelante? Allá es adonde vamos. Seguramente la batalla ya ha comenzado.', 0),
(24973, 'esMX', 'Bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo la infestación. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n.', 0),
(26802, 'esMX', 'Gracias, $n. Esta armadura te servirá de ayuda. $B$BEspero que, al menos, te dé más suerte que a su último portador...', 0),
(28672, 'esMX', '¿Qué tenemos aquí? $gUn:Una; $c $gnovato y listo:novata y lista; para el combate, ¿eh?', 0),
(24961, 'esMX', '¿Dices que salió corriendo? Qué pena.$B$BMuy bien. Mientras conserve su libre albedrío habrá esperanza.', 0),
(28651, 'esMX', 'Que la Dama Oscura te proteja, $n.', 0),
(26801, 'esMX', 'Tu fuerza crece por momentos, $n. No es la primera vez que veo individuos como tú. No tardarás en irte de Camposanto y acometer tareas más importantes. Pero nunca olvides dónde comenzaste.$b$bLlegarás muy lejos, $c.', 0),
(26800, 'esMX', 'Buen trabajo, $n, sabía que no eras $gun:una; inútil.$b$bTen, quédate con uno de estos. Los guardias de la Muerte tienen montones enteros de estos trastos cogiendo polvo.', 0),
(25089, 'esMX', 'Últimamente esas Val\'kyr no dan abasto resucitando a $glos novatos:las novatas; como tú. Esta mañana ya he visto varias docenas de cadáveres corriendo por estas colinas.$b$bPero tú eres $gel:la; $c más $gprometedor:prometedora; que he visto en lo que va de día.', 0),
(24960, 'esMX', 'Has hecho bien, $c. Como puedes ver, no todos nos hemos resignado a nuestro destino. Me alegra ver que estás deseando trabajar, al menos.$b$bValdred será un recurso valioso para los Renegados. En cuanto a los otros dos... No hay mucho que podamos hacer. No podemos obligarlos a que se unan a nosotros.', 0),
(28652, 'esMX', '¿Sí? ¿Y tú quién eres?', 0),
(26799, 'esMX', 'Ni siquiera el poder de las Val\'kyr bastó para salvar a estas criaturas. Estaban condenadas desde el principio.$b$bTe conseguí algo de equipo, $n. No es mucho, pero te ayudará.', 0),
(28608, 'esMX', 'Es exactamente lo que necesitaba. Vas a ser una gran baza para los Renegados, $n.$b$bSe rumorea que en tu vida anterior fuiste $gun:una; $c de renombre. A lo mejor debería asignarte una tarea más emocionante.', 0),
(24959, 'esMX', 'Hola. Tú debes de ser... ¿$n?', 0);

DELETE FROM `quest_request_items_locale` WHERE `ID` IN (28608, 26802) AND `Locale` IN ('esES', 'esMX');

INSERT INTO `quest_request_items_locale` (`ID`, `Locale`, `CompletionText`, `VerifiedBuild`) VALUES
(28608, 'esES', 'Encontrarás los objetos en el Sepulcro Sombrío. Creo que me los dejé en mi mesa de trabajo.', 0),
(26802, 'esES', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0),
(28608, 'esMX', 'Encontrarás los objetos en el Sepulcro Sombrío. Creo que me los dejé en mi mesa de trabajo.', 0),
(26802, 'esMX', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0);

UPDATE `creature` SET `position_x`=1704.5099565859375, `position_y`=1701.579956984375, `position_z`=136.1975860595703125, `orientation`=1.675516128540039062 WHERE `id`=49044;

DELETE FROM `gossip_menu_option_locale` WHERE `MenuID` IN (12489, 11133, 12484, 12487, 12488, 12485, 12486, 12483) AND `Locale` IN ('esES', 'esMX');

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `ID`, `Locale`, `OptionText`, `BoxText`, `VerifiedBuild`) VALUES
(12489, 0, 'esES', 'Habla con el enterrador Mordo. Él te dirá lo que tienes que hacer. Eso es todo por ahora.',NULL, 0),
(11133, 0, 'esES', 'No eres horrible, Lilian... eres una de nosotros. Toma, mírate en este espejo y compruébalo tú misma.',NULL, 0),
(12484, 0, 'esES', 'Lilian, ¿te das cuenta de que tú también estás no-muerta?',NULL, 0),
(12487, 0, 'esES', '¿No lo recuerdas? Moriste.',NULL, 0),
(12488, 0, 'esES', 'Tranquilízate, Valdred. Probablemente el enterrador Mordo te cosió unas nuevas.',NULL, 0),
(12485, 0, 'esES', 'No he venido a luchar. Solo me han pedido que hable contigo.',NULL, 0),
(12486, 0, 'esES', 'Eres libre de hacer lo que quieras.',NULL, 0),
(12483, 0, 'esES', 'No soy una abominación, soy un simple no-muerto. Solo quiero hablar contigo.',NULL, 0),
(12489, 0, 'esMX', 'Habla con el enterrador Mordo. Él te dirá lo que tienes que hacer. Eso es todo por ahora.',NULL, 0),
(11133, 0, 'esMX', 'No eres horrible, Lilian... eres una de nosotros. Toma, mírate en este espejo y compruébalo tú misma.',NULL, 0),
(12484, 0, 'esMX', 'Lilian, ¿te das cuenta de que tú también estás no-muerta?',NULL, 0),
(12487, 0, 'esMX', '¿No lo recuerdas? Moriste.',NULL, 0),
(12488, 0, 'esMX', 'Tranquilízate, Valdred. Probablemente el enterrador Mordo te cosió unas nuevas.',NULL, 0),
(12485, 0, 'esMX', 'No he venido a luchar. Solo me han pedido que hable contigo.',NULL, 0),
(12486, 0, 'esMX', 'Eres libre de hacer lo que quieras.',NULL, 0),
(12483, 0, 'esMX', 'No soy una abominación, soy un simple no-muerto. Solo quiero hablar contigo.',NULL, 0);
