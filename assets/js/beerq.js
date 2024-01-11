(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f()}else if(typeof define==="function"&&define.amd){define([],f)}else{var g;if(typeof window!=="undefined"){g=window}else if(typeof global!=="undefined"){g=global}else if(typeof self!=="undefined"){g=self}else{g=this}g.beerq = f()}})(function(){var define,module,exports;return (function(){function r(e,n,t){function o(i,f){if(!n[i]){if(!e[i]){var c="function"==typeof require&&require;if(!f&&c)return c(i,!0);if(u)return u(i,!0);var a=new Error("Cannot find module '"+i+"'");throw a.code="MODULE_NOT_FOUND",a}var p=n[i]={exports:{}};e[i][0].call(p.exports,function(r){var n=e[i][1][r];return o(n||r)},p,p.exports,r,e,n,t)}return n[i].exports}for(var u="function"==typeof require&&require,i=0;i<t.length;i++)o(t[i]);return o}return r})()({1:[function(require,module,exports){
"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.BeerQuote = BeerQuote;
var _utils = require("./utils.js");
var _quotes = require("./quotes.js");
function BeerQuote(language) {
  let _quoteDictList = (0, _quotes.quotes)(language);
  let _languagesList = (0, _quotes.languages)();
  let _numberOfQuotes = _quoteDictList.length;
  let _authorList = _quoteDictList.map(quoteDict => quoteDict.author);
  let _quoteList = _quoteDictList.map(quoteDict => quoteDict.quote);
  let _vectorUtils = (0, _utils.VectorUtils)();
  function getLanguagesList() {
    /**
     * Return the list of availabe languages
     */
    return _languagesList;
  }
  function getAuthorList() {
    /**
     * Return the list of authors
     */
    return _vectorUtils.getUnique(_authorList);
  }
  function getAllQuotes() {
    /**
     * Return all quotes
     */
    return _quoteDictList;
  }
  function getRandomQuotes(numberOfQuotes) {
    /**
     * Return a list of random quotes
     */
    let quoteIndeces = _vectorUtils.getVectorofRandomIndices(0, _numberOfQuotes, numberOfQuotes, true);
    return quoteIndeces.map(quoteIndex => _quoteDictList[quoteIndex]);
  }
  function getQuotesFromIndices(quoteIndeces) {
    /**
     * Return a list of quotes from list of indeces
     */
    return quoteIndeces.map(quoteIndex => _quoteDictList[quoteIndex]);
  }
  function getQuotesFromAuthor(authorName) {
    /**
     * Return the quotes of a specific author
     */
    let quoteIndeces = _vectorUtils.getAllIndexOf(_authorList, authorName);
    return quoteIndeces.map(quoteIndex => _quoteDictList[quoteIndex]);
  }
  function getRandomQuote() {
    /**
     * Return a random quote
     */
    let quoteIndex = _vectorUtils.getRandomIndex(0, _numberOfQuotes);
    return {
      quote: _quoteList[quoteIndex],
      author: _authorList[quoteIndex]
    };
  }
  function getQuoteFromIndex(quoteIndex) {
    /**
     * Return a quote from an index
     */
    return {
      quote: _quoteList[quoteIndex],
      author: _authorList[quoteIndex]
    };
  }
  function getRandomQuoteFromAuthor(authorName) {
    /**
     * Return a random quote from a specific author
     */
    let quoteIndeces = _vectorUtils.getAllIndexOf(_authorList, authorName);
    let randomIndex = _vectorUtils.getRandomIndex(0, quoteIndeces.length);
    let quoteIndex = quoteIndeces[randomIndex];
    return {
      quote: _quoteList[quoteIndex],
      author: _authorList[quoteIndex]
    };
  }
  return {
    getLanguagesList,
    getAuthorList,
    getAllQuotes,
    getRandomQuotes,
    getQuotesFromIndices,
    getQuotesFromAuthor,
    getRandomQuote,
    getQuoteFromIndex,
    getRandomQuoteFromAuthor
  };
}

},{"./quotes.js":2,"./utils.js":3}],2:[function(require,module,exports){
"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.languages = languages;
exports.quotes = quotes;
let quoteListEng = [{
  quote: "Now is the time to drink!",
  author: "Horace"
}, {
  quote: "Beer is the proof that god loves us and wants us to be happy.",
  author: "Benjamin Franklin"
}, {
  quote: "Sobriety diminishes, discriminates and says no; drunkenness expands, unites and says yes.",
  author: "William James"
}, {
  quote: "Give a man a beer, waste an hour, teach a man to brew, and waste a lifetime!",
  author: "Bill Owen"
}, {
  quote: "A man's got to believe in something. I believe I'll have another drink.",
  author: "W. C. Fields"
}, {
  quote: "Beer seems like an even better idea after you've had some beer.",
  author: "Steven Hall"
}, {
  quote: "Alcohol is not the answer to life's question...at least it helps you forget the question.",
  author: "Vijay Mallya"
}, {
  quote: "God has a brown voice, as soft and full as beer.",
  author: "Anne Sexton"
}, {
  quote: "Come, landlord, fill a flowing bowl until it does run over; tonight we will all merry be - tomorrow we'll get sober.",
  author: "John Fletcher"
}, {
  quote: "Good people drink good beer.",
  author: "Hunter S. Thompson"
}, {
  quote: "Fermentation equals civilisation.",
  author: "John Ciardi"
}, {
  quote: "Stay with the beer. Beer is continuous blood. A continuous lover.",
  author: "Charles Bukowski"
}, {
  quote: "The drink you like the best should be the drink you drink the most.",
  author: "J. B. Burgess"
}, {
  quote: "All is fair in love and beer.",
  author: "Anonymous"
}, {
  quote: "Nothing ever tasted better than a cold beer on a beautifull afternoon with nothing to look forward to than more of the same.",
  author: "Hugh Hood"
}, {
  quote: "When I drink, I think; and when I think, I drink.",
  author: "Francois Rabelais"
}, {
  quote: "Quaintest thoughts - queerest fancies come to life and fade away; what care I how time advances?I am drinking today.",
  author: "Edgar Allan Poe"
}, {
  quote: "No soldier can fight unless he is properly fed on beef and beer.",
  author: "John Churchill"
}, {
  quote: "Keeping one's guest supplied with liquor is the first law of hospitality.",
  author: "Margaret Way"
}, {
  quote: "The church is near, but the road is icy. The bar is far, but I will walk carefully.",
  author: "Russian proverb"
}, {
  quote: "God made yeast, as well as dough, and loves fermantation just as dearly as he loves vegetation.",
  author: "Ralph Waldo Emerson"
}, {
  quote: "When I read about the evils of drinking, I gave up reading.",
  author: "Henny Youngman"
}, {
  quote: "In wine there is wisdom, in beer there is freedom, in water there is bacteria.",
  author: "Benjamin Franklin"
}, {
  quote: "If this dogs do you bite, soon as out of your bed, take a hair of the tail in the morning.",
  author: "Scottish proverb"
}, {
  quote: "Alcohol, taken in sufficient quantities, may produce all the effects of drunkenness.",
  author: "Oscar Wilde"
}, {
  quote: "Meet me down in the bar! We'll drink breakfast together.",
  author: "W. C. Fields"
}, {
  quote: "A drink a day keeps the shrink away.",
  author: "Edward Abbey"
}, {
  quote: "Sometimes too much to drink is barely enough.",
  author: "Mark Twain"
}, {
  quote: "I drink when I have occasion, and sometimes when I have no occasion.",
  author: "Miguel de Cervantes"
}, {
  quote: "Never trust a man who doesn't drink.",
  author: "James Crumley"
}, {
  quote: "The mouth of a perfectly happy man is filled with beer.",
  author: "Ancient Egyptian proverb"
}, {
  quote: "The worse you are at thinking, the better you are at drinking.",
  author: "Terry Goodkind"
}, {
  quote: "But I'm not so think as you drunk I am.",
  author: "Sir John Collings Squire"
}, {
  quote: "There’s alcohol in plant and tree. It must be nature’s plan that there should be in fair degree some alcohol in man.",
  author: "Sir Alan Patrick Herber"
}, {
  quote: "Ale, man, ale’s the stuff to drink for fellows whom it hurts to think.",
  author: "Alfred Edward Housman"
}, {
  quote: "Sober or blotto, this is your motto: keep muddling through.",
  author: "Sir Pelham Grenville Wodehouse"
}, {
  quote: "Drink is the feast of reason and the flow of soul.",
  author: "Alexander Pope"
}, {
  quote: "I have taken more out of alcohol than alcohol has taken out of me.",
  author: "Winston Churchill"
}, {
  quote: "The problem with the world is that everyone is a few drinks behind.",
  author: "Humphrey Bogart"
}, {
  quote: "When I’m drunk, I bite.",
  author: "Bette Midler"
}, {
  quote: "It takes only one drink to get me drunk. The trouble is, I can’t remember if it’s the thirteenth or the fourteenth.",
  author: "George Burns"
}, {
  quote: "Abstainer: a weak person who yields to the temptation of denying himself a pleasure.",
  author: "Ambrose Bierce"
}, {
  quote: "Drink what you want; drink what you’re able. If you are drinking with me, you’ll be under the table.",
  author: "Anonymous"
}, {
  quote: "May your glass be ever full, may the roof over your head be always strong, and may you be in heaven half an hour before the devil knows you’re dead.",
  author: "Irish toast"
}, {
  quote: "What harm in drinking can there be, since punch and life so well agree?",
  author: "Thomas Blacklock"
}, {
  quote: "Drinking is a way of ending the day.",
  author: "Ernest Hemingway"
}, {
  quote: "Health – what my friends are always drinking to before they fall down.",
  author: "Phyllis Diller"
}, {
  quote: "Man, being reasonable, must get drunk; the best of life is but intoxication.",
  author: "Lord Byron"
}, {
  quote: "You have to drink, otherwise you’d go stark staring sober.",
  author: "Keith Waterhouse"
}, {
  quote: "Alcohol is a misunderstood vitamin.",
  author: "Sir Pelham Grenville Wodehouse"
}, {
  quote: "Woman first tempted man to eat; he took to drinking of his own accord.",
  author: "John R. Kemble"
}, {
  quote: "If I had to live my life over, I’d live over a saloon.",
  author: "W. C. Fields"
}, {
  quote: "Topping beer off with wine – that’s fine!",
  author: "German proverb"
}, {
  quote: "What’s drinking?A mere pause from thinking!",
  author: "Lord Byron"
}, {
  quote: "Here’s to alcohol,the rose-coloured glasses of life.",
  author: "F. Scott Fitzgerald"
}, {
  quote: "Milk is for babies, when you grown up you have to drink beer.",
  author: "Arnold Schwarzenegger"
}, {
  quote: "He was a wise man who invented beer.",
  author: "Plato"
}, {
  quote: "What two ideas are more inseparable than beer and britannia?",
  author: "Sydney Smith"
}, {
  quote: "You can’t be a real country unless you have a beer and an airline.",
  author: "Frank Zappa"
}, {
  quote: "Beauty is in the eye of the beer holder.",
  author: "Kinky Friedman"
}, {
  quote: "Beer, it’s the best damn drink in the world.",
  author: "Jack Nicholson"
}, {
  quote: "There is no such thing as a bad beer. It’s that some taste better than others.",
  author: "Billy Carter"
}, {
  quote: "I’m gaining weight the right way: I’m drinking beer.",
  author: "Johnny Damon"
}, {
  quote: "I have respect for beer.",
  author: "Russell Crowe"
}, {
  quote: "Let a man walk ten miles steadily on a hot summer’s day along a dusty english road, and he will soon discover why beer was invented.",
  author: "Gilbert Keith Chesterton"
}, {
  quote: "Not all chemical are bad. Without chemicals such as hydrogen and oxygen for example,  there would be no way to make water, a vital ingredient in beer.",
  author: "Dave Barry"
}, {
  quote: "Ah, drink again this river that is the taker-away of pain, and the giver-back of beauty!",
  author: "Edna St. Vincent Millay"
}, {
  quote: "Give me a woman who loves beer and I will conquer the world.",
  author: "Kaiser Wilhelm II"
}, {
  quote: "No animal ever invented anything so bad as drunkenness – or so good as drink.",
  author: "Gilbert Keith Chesterton"
}, {
  quote: "Beer is not a good cocktail-party drink, especially in a home where you don’t know where the bathroom is.",
  author: "Billy Carter"
}, {
  quote: "Beer makes you feel the way you ought to feel without beer.",
  author: "Henry Lawson"
}, {
  quote: "Alcohol may be man’s worst enemy, but the bible says love your enemy.",
  author: "Frank Sinatra"
}, {
  quote: "The sacred pint alone can unbind the tongue.",
  author: "James Joyce"
}, {
  quote: "I’ve never been thrown out of a pub, but I’ve fallen into quite a few.",
  author: "Benny Bellamacina"
}, {
  quote: "Beer, if drunk in moderation, softens the temper, cheers the spirit and promotes health.",
  author: "Thomas Jefferson"
}, {
  quote: "I only take a drink on two occasions – when I’m thirsty and when I’m not.",
  author: "Brendan Behan"
}, {
  quote: "Teetotallers lack the sympathy and generosity of men that drink.",
  author: "William Henry Davies"
}, {
  quote: "A man who lies about beer makes enemies.",
  author: "Stephen King"
}, {
  quote: "For a quart of ale is a dish for a king.",
  author: "William Shakespeare"
}, {
  quote: "Without question, the greatest invention in the history of mankind is beer.",
  author: "Dave Barry"
}, {
  quote: "A man ought to get drunk at least twice a year...so he won’t let himself get snotty about it.",
  author: "Raymond Chandler"
}, {
  quote: "You’re not drunk if you can lie on the floor without holding on.",
  author: "Dean Martin"
}, {
  quote: "A woman drove me to drink and I didn’t even have the decency to thank her.",
  author: "W. C. Fields"
}, {
  quote: "Always do sober what you said you’d do drunk. That will teach you to keep your mouth shut.",
  author: "Ernest Hemingway"
}, {
  quote: "Twenty-four hours in a day, 24 beers in a case. Coincidence?",
  author: "Steven Wright"
}, {
  quote: "Time is never wasted when you’re wasted all the time.",
  author: "Catherine Zandonella"
}, {
  quote: "A fine beer may be judged with only one sip, but it’s better to be thoroughly sure.",
  author: "Czech proverb"
}, {
  quote: "A man can hide all things, excepting twain – that he is drunk, and that he is in love.",
  author: "Antiphanes"
}, {
  quote: "I fear the man who drinks water and so remembers this morning what the rest of us said last night.",
  author: "Greek proverb"
}, {
  quote: "Too much work and no vacation, deserves at least a small libation.",
  author: "Oscar Wilde"
}, {
  quote: "He that drinketh strong beer and goes to bed tight mellow, lives as he ought to live and dies a hearty fellow.",
  author: "Traditional toast"
}, {
  quote: "Give my people plenty of beer, good beer, and cheap beer, and you will have no  revolution among them.",
  author: "Queen Victoria"
}, {
  quote: "If you ever reach total enlightenment while drinking beer, I bet it makes beer shoot out your nose.",
  author: "Jack Handey"
}, {
  quote: "It takes beer to make thirst worthwhile.",
  author: "German proverb"
}, {
  quote: "Beer...A high and mighty liquor.",
  author: "Julius Caesar"
}, {
  quote: "He is not deserving the name of englishman who speaketh against ale, that is, good ale.",
  author: "George Borrow"
}, {
  quote: "’ere’s to english women an’ a quart of english beer.",
  author: "Rudyard Kipling"
}, {
  quote: "No poems can live long or please that are written by water-drinkers.",
  author: "Horace"
}, {
  quote: "Alcohol may not solve your problems, but neither will water or milk.",
  author: "Anonymous"
}, {
  quote: "Beer needs baseball, and baseball needs beer – it has always been thus.",
  author: "Peter Richmond"
}, {
  quote: "I never met a pub I didn’t like.",
  author: "Pete Slosberg"
}, {
  quote: "Fermentation may have been a greater discovery than fire.",
  author: "David Rains Wallace"
}, {
  quote: "Who does not love beer, wine, women and song remains a fool his whole life long.",
  author: "Carl Worner"
}, {
  quote: "I envy people who drink – at least they know what to blame everything on.",
  author: "Oscar Levant"
}, {
  quote: "Oh, you hate your job?...There’s a support group for that. It’s called everybody, and they meet at the bar.",
  author: "Drew Carey"
}, {
  quote: "Drink because you are happy, but never because you are miserable.",
  author: "Gilbert Keith Chesterton"
}, {
  quote: "Of course, I just said I was a writer.",
  author: "Stephen King on being asked if he drank"
}, {
  quote: "I would give all my fame for a pot of ale, and safety.",
  author: "William Shakespeare"
}, {
  quote: "Ninety-nine per cent of all problems can be solved by money – and for the other 1 per cent there’s alcohol.",
  author: "Quentin R. Bufogle"
}, {
  quote: "Ignorance is a lot like alcohol: the more you have of it, the less you are able to see its effect on you.",
  author: "Jay M. Bylsma"
}, {
  quote: "Those who drink beer will think beer.",
  author: "Washington Irving"
}, {
  quote: "I’m a drinker with writing problems.",
  author: "Brendan Behan"
}, {
  quote: "When you stop drinking, you have to deal with this marvellous personality that started you drinking in the first place.",
  author: "Jimmy Breslin"
}, {
  quote: "I never drink while I’m working, but after a few glasses I get ideas that would never have occurred to me dead sober.",
  author: "Irwin Shaw"
}, {
  quote: "The only cure for a real hangover is death.",
  author: "Robert Benchley"
}, {
  quote: "I have fed purely upon ale; I have eat my ale, drank my ale, and I always sleep upon ale.",
  author: "George Farquhar"
}, {
  quote: "Nothing gives a sensation better than a beer!Nothing builds a relation better than a beer!",
  author: "Anshul Dubey"
}, {
  quote: "Alcohol is like love. The first kiss is magic, the second is intimate, the third is routine.",
  author: "Raymond Chandler"
}, {
  quote: "Alcohol is the anesthesia by which we endure the operation of life.",
  author: "George Bernard Shaw"
}, {
  quote: "Alcohol is necessary for a man so that he can have a good opinion of himself, undisturbed by the facts.",
  author: "Finley Peter Dunne"
}, {
  quote: "I drink to make other people more interesting.",
  author: "Ernest Hemingway"
}, {
  quote: "Even though a number of people have tried, no one has yet found a way to drink for a living.",
  author: "Jean Kerr"
}, {
  quote: "Bacchus, n. a. convenient deity invented by the ancients as an excuse for getting drunk.",
  author: "Ambrose Bierce"
}, {
  quote: "The worst thing about some men is that when they are not drunk they are sober.",
  author: "William Butler Yeats"
}, {
  quote: "I drink exactly as much as I want, and one drink more.",
  author: "Henry Louis Mencken"
}, {
  quote: "The drunk mind speaks the sober heart.",
  author: "Anonymous"
}, {
  quote: "Know thyself, especially thyself after a couple of drinks.",
  author: "Robert Brault"
}, {
  quote: "Drunkenness is nothing but voluntary madness.",
  author: "Seneca the Younger"
}, {
  quote: "One more drink and I’d have been under the host!",
  author: "Dorothy Parker"
}, {
  quote: "My grandmother is over 80 and still doesn’t need glasses. Drinks right out the bottle.",
  author: "Henny Youngman"
}, {
  quote: "Drink the first. Sip the second slowly. Skip the third.",
  author: "Knute Rockne"
}, {
  quote: "A little bit of beer is divine medicine.",
  author: "Paracelsus"
}, {
  quote: "I distrust camels, and anyone else who can go a week without a drink.",
  author: "Joe E. Lewis"
}, {
  quote: "Most people hate the taste of beer to begin with. It is, however, a prejudice that many people have been able to overcome.",
  author: "Winston Churchill"
}, {
  quote: "But if at church they would give us some ale...we’d sing and we’d pray all the live-long day.",
  author: "William Blake"
}, {
  quote: "When you’re thirsty and it seems that you could drink the entire ocean, that’s faith; when you start to drink and finish only a glass or two, that’s science.",
  author: "Anton Chekhov"
}, {
  quote: "By the time a bartender knows what drink a man will have before he orders, there is little else about him worth knowing.",
  author: "Don Marquis"
}, {
  quote: "Fishing, with me, has always been an excuse to drink in the daytime.",
  author: "Jimmy Cannon"
}, {
  quote: "I have two ambitions in life: one is to drink every pub dry, the other is to sleep with every woman on earth.",
  author: "Oliver Reed"
}, {
  quote: "Did your mother never tell you not to drink on an empty head?",
  author: "Billy Connolly"
}, {
  quote: "The best way to judge a pub is by the albums on its jukebox.",
  author: "Ned Beauman"
}, {
  quote: "Of course one should not drink much, but often.",
  author: "Henri de Toulouse-Lautrec"
}, {
  quote: "Drink not the third glass, which thou canst not tame, when once it is within theen.",
  author: "George Herbert"
}, {
  quote: "It is not how much we have,but how much we enjoy, that makes happiness.",
  author: "Charles Spurgeon"
}, {
  quote: "Simply enjoy life and the great pleasures that come with it.",
  author: "Karolina Kurkova"
}, {
  quote: "I have a theory that the secret of martial happiness is simple: drink in different pubs to your other half.",
  author: "Jilly Cooper"
}, {
  quote: "Beer speaks. People mumble.",
  author: "Tony Magee"
}, {
  quote: "Love makes the world go round?Not at all. Whisky makes it go round twice as fast.",
  author: "Compton Mackenzie"
}, {
  quote: "There is nothing for a case of nerves like a case of beer.",
  author: "Joan Goldstein"
}, {
  quote: "The difference between a drunk and an alcoholic is that a drunk doesn/t have to attend all those meetings.",
  author: "Arthur Lewis"
}, {
  quote: "I’m not a heavy drinker, I can sometimes go for hours without touching a drop.",
  author: "Noel Coward"
}, {
  quote: "Beer...An intoxicating golder brew that re-emerges virtually unchanged an hour later.",
  author: "Rick Bayan"
}, {
  quote: "There is nothing which has been yet contrived by man, by which so much happiness is produced as by a good tavern or inn.",
  author: "Samuel Johnson"
}, {
  quote: "How much of our literature, our political life, our friendships and love affairs, depend on being able to talk peacefully in a bar!",
  author: "John Wain"
}, {
  quote: "The pub is the internet. It’s where information is gathered, collated and addressed.",
  author: "Rhys Ifans"
}, {
  quote: "Shoulder the sky, my lad, and drink you ale.",
  author: "Alfred Edward Housman"
}, {
  quote: "Two beer or not two beer: that is the passion.",
  author: "Homer Simpson"
}];
let quoteListIta = [{
  quote: "I teologi pensano di sapere le domande.Gli scienziati pensano di sapere le risposte.Io penso che sia ora di bere un’altra birra.",
  author: "Anonimo"
}, {
  quote: "Tutti noi abbiamo bisogno di credere in qualcosa: io credo che tra poco mi farò una birra.",
  author: "Homer Simpson"
}, {
  quote: "Come ci si può divertire in una festa in cui le birre sono calde e le donne sono fredde?",
  author: "Groucho Marx"
}, {
  quote: "Quando morirò, seppellitemi in una cassa. Di birra.",
  author: "Anonimo"
}, {
  quote: "Andrà tutto come deve andare, quindi apriti una birra e goditi la vita.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Sarebbe un mondo migliore se la birra gonfiasse le tette anziché la pancia.",
  author: "Anonimo"
}, {
  quote: "La gente porta rancore, la notte porta consiglio, la mamma porta pazienza, io porto le birre.",
  author: "Anonimo"
}, {
  quote: "Verba volant. Scripta manent. Birra Tennent’s",
  author: "Anonimo"
}, {
  quote: "Mi godo il sollievo di questa breve brezza, e provo a convincermi che la realtà sia questa: leggera, ilare e schiumosa di birra.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Quando bevi una birra da solo, non sei veramente solo. La birra è lì con te. Ti ascolta, ti ama, ti abbraccia e non ti giudica.",
  author: "Anonimo"
}, {
  quote: "Metti da parte i tuoi doveri. Prendi un bottiglia di birra, assapora l’aria della sera, respira e sorridi, e ama le parole di chi ti sta intorno.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Amo il gusto della birra, la sua schiuma bianca, viva, la sua profondità ramata, il mondo che sorge all’improvviso attraverso le pareti brune e umide del vetro...la spuma negli angoli.",
  author: "Dylan Thomas"
}, {
  quote: "Senza ombra di dubbio, la più grande invenzione nella storia dell’umanità è la birra. Oh, certo, sicuramente anche la ruota è stata una gran bella invenzione, ma vi assicuro che la ruota non va altrettanto bene con la pizza.",
  author: "Anonimo"
}, {
  quote: "Se Adamo avesse saputo fare la birra, giammai Eva avrebbe potuto tentarlo, con la sua mela.",
  author: "Marcel Gocar"
}, {
  quote: "Nella mia vita mi sono innamorato solo di una bottiglia di birra e di uno specchio.",
  author: "Anne Sexton"
}, {
  quote: "Dio ha una voce bionda, morbida e piena, come la birra.",
  author: "Sid Vicious"
}, {
  quote: "Ci sono giornate che vanno affrontate con un sorriso, altre con una birra.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Se non hanno mai dato il premio nobel a quello che ha inventato la birra non sono credibili.",
  author: "Anonimo"
}, {
  quote: "Tu porta una cassa di birra e di pensieri sognanti e un paio di sorrisi giusti. Al resto ci penso io.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Non è la birra una santa libagione di sincerità? La pozione che dissipa ogni ipocrisia, ogni sciarada di belle maniere? Una bevanda che non fa altro che incitare i suoi seguaci a urinare in tutta innocenza, ad aumentare di peso in tutta franchezza.",
  author: "Milan Kundera"
}, {
  quote: "Mi siedo qui e bevo la mia buona birra Wittenbergische e il regno di Dio viene da sé.",
  author: "Martin Lutero"
}, {
  quote: "Una pinta di birra è un pasto da re.",
  author: "William Shakespeare"
}, {
  quote: "La birra ha un buon sapore in gola, freddo e amaro, ed i tre ragazzi e la birra e la gratuità della situazione mi fanno sentire bene e ridere sempre. Rido, e il mio rossetto lascia una macchia rossa come una falce di luna insanguinata sulla parte superiore della lattina di birra.",
  author: "Sylvia Plath"
}, {
  quote: "Esistono bionde intelligenti? Si, le birre.",
  author: "Anonimo"
}, {
  quote: "Un pub conosce tanti segreti quanti ne conosce una chiesa.",
  author: "Joyce Carey"
}, {
  quote: "La birra non è la soluzione ai problemi ma alcool + malto + luppolo + lievito è una soluzione perfetta.",
  author: "Fabrizio Caramagna"
}, {
  quote: "L’acqua può diventare anche una buona bevanda,se mescolata con malto e luppolo!",
  author: "Proverbio tedesco"
}, {
  quote: "Quanta birra c’è nell’intelligenza tedesca?",
  author: "Friedrich Nietzsche"
}, {
  quote: "Bere una birra è come fare sesso. Se lo fai in due è meglio.",
  author: "Anonimo"
}, {
  quote: "Come quelle risate che partono così, squillanti e meravigliosamente scomposte, tra una fetta di pizza e un bicchiere di birra.",
  author: "Fabrizio Caramagna"
}, {
  quote: "Ho un sacco di problemi. Posalo nell’angolo che ci facciamo una birra.",
  author: "Anonimo"
}, {
  quote: "Quand’ero giovane e ordinavo una birra te la davano dopo 30 secondi. Adesso dopo 30 secondi ti arriva il cameriere tatuato che ti racconta le origini e il processo di preparazione di ogni singola birra del menù che quando ha finito ti ricoverano in ospedale per disidratazione.",
  author: "Anonimo"
}, {
  quote: "Date a un uomo una birra e ci perderà un’ora. Insegnategli a farsela da se e ci perderà una vita intera.",
  author: "The Home Brew Company"
}, {
  quote: "Chi beve birra, si addormenta più velocemente; chi dorme più a lungo, non pecca; chi non pecca, entra in Paradiso! Beviamo birra!",
  author: "Martin Lutero"
}, {
  quote: "La bocca di un uomo completamente felice è piena di birra.",
  author: "Massima dell’antico Egitto"
}, {
  quote: "Basta una birra a colazione e le ragnatele se ne vanno, la voce ti si alza di due ottave e ti sorge un bel sole dentro.",
  author: "Robert De Niro"
}, {
  quote: "In Belgio, il magistrato ha la dignità di un principe, ma per Bacco, è altrettanto vero che il birraio è un re.",
  author: "Emile Verhaeren"
}, {
  quote: " Una birra, per favore. Signore, questa è una gelateria. Ah, ok. In cono grande, allora...",
  author: "Anonimo"
}, {
  quote: "24 ore in un giorno, 24 birre in una cassa. Una coincidenza?",
  author: "Stephen Wright"
}, {
  quote: "Tenetevi le vostre biblioteche, tenetevi le vostre istituzioni penali, tenetevi le vostre scuole dementi e dateci della birra. Credete che l’uomo abbia bisogno di regole, ma egli vuole della birra. L’umanità non ha bisogno delle vostra morale, vuole della birra. Non ha bisogno delle vostre letture o della vostra carità. Lo spirito dell’uomo è stato nutrito di cose indigeste, e adesso questo spirito vuole fare buon uso della birra.",
  author: "Henri Miller"
}, {
  quote: "Resta con la tua birra, la birra è un flusso continuo di sangue, un’amante continua.",
  author: "Charles Bukowski"
}, {
  quote: "Il pane è l’energia della vita, ma la birra è la vita stessa.",
  author: "Proverbio inglese"
}, {
  quote: "La fermentazione e la civilizzazione sono inseparabili. ",
  author: "John Ciardi"
}, {
  quote: "Non ci sono cattive birre. Alcune hanno semplicemente un gusto migliore di altre.",
  author: "Billy Carter"
}, {
  quote: "Ho 29 anni. Per i 18enni sono un vecchio. Per i 40enni sono un giovane. Per i 60enni sono un ragazzo. Per me, una birra. Fredda. Grazie.",
  author: "Anonimo"
}, {
  quote: "E’ un buon vento quello che ha spinto gli uomini verso la birra.",
  author: "Washington Irving"
}, {
  quote: "L’eternità è fatta dei primi sorsi di birra.",
  author: "Proverbio tedesco"
}, {
  quote: "Se uno non ha amici veri, con cui farsi una birra e porsi domande senza risposta, qualcosa ha sbagliato.",
  author: "Anonimo"
}, {
  quote: "Chiunque produrrà birra di cattiva qualità sarà preso con la forza e gettato nel letame.",
  author: "Editto della città di Danzica, XI secolo"
}, {
  quote: "Chi siamo? Da dove veniamo? Dove stiamo andando?Perché la birra al limone?",
  author: "Anonimo"
}, {
  quote: "Quando la bevo sto benissimo: l’umore è allegro, il cuore contento e il fegato felice.",
  author: "Tavoletta sumera, 3600 a.C."
}, {
  quote: "Era un uomo saggio chi ha inventato la birra.",
  author: "Platone"
}, {
  quote: "La birra, al contrario del vino, non ha bisogno di sole per maturare: la luna le è ampiamente sufficiente.",
  author: "Jacques Josse"
}, {
  quote: "Chi acquista un terreno, acquista delle pietre. Chi acquista della carne, acquista degli ossi. Chi acquista delle uova, acquista dei gusci.Ma chi acquista una buona birra,fa un affare.",
  author: "Proverbio inglese"
}, {
  quote: "Com’è gradevole il tiglio nelle sere di Giugno! L’aria è si dolce che a palpebre chiuse annusi il vento che risuona; la città è vicina e porta aromi di birra e di vino.",
  author: "Arthur Rimbaud"
}, {
  quote: "La fermentazione della birra potrebbe essere stata una scoperta più grande del fuoco.",
  author: "David Wallace"
}, {
  quote: "Quando morirò, voglio decompormi in un barile di birra ed essere servito in tutti i pub di Dublino.",
  author: "JpDonleavy"
}, {
  quote: "Il bello della birra è che si può bere dalle undici del mattino fino a colazione.",
  author: "Klaus Augenthaler"
}, {
  quote: "E’ vero, c’è birra gratis nel paradiso irlandese.",
  author: "Kevin Hearne"
}, {
  quote: "Bere birra analcolica e’ come ascoltare un film porno alla radio.",
  author: "Anonimo"
}, {
  quote: "Assetato portò la pinta alle labbra, e, come il suo fresco ristoro cominciò a lenire la gola, ringraziò il cielo che in un mondo così pieno di malvagità ci fosse ancora una cosa buona come la birra.",
  author: "Rafael Sabatini"
}, {
  quote: "Non tutta la chimica è cattiva. Senza la chimica, come l’idrogeno e l’ossigeno per esempio, non ci sarebbe modo di fare l’acqua, un ingrediente fondamentale della birra.",
  author: "Dave Barry"
}, {
  quote: "La cucina inglese: se è fredda, c’è della zuppa. Se è calda, c’è della birra.",
  author: "Proverbio"
}, {
  quote: "La perfezione? Una bella donna nuda che spina birra dai capezzoli.",
  author: "Paolo Burini"
}, {
  quote: "Chi beve birra light non ama il gusto della birra, gli piace soltanto pisciare parecchio.",
  author: "Anonimo"
}, {
  quote: "Se ne vanno sempre i migliori e mai quelli che bevono la birra nei bicchieri di plastica.",
  author: "Anonimo"
}, {
  quote: "Nel vino c’è la saggezza, nella birra c’è la forza, nell’acqua ci sono i batteri.",
  author: "Proverbio tedesco"
}, {
  quote: "Buona birra è cibo, bevanda e vestito.",
  author: "Proverbio tedesco"
}, {
  quote: "Mostratemi una donna che ami davvero il gusto sulla birra, e io conquisterò il mondo.",
  author: "Guglielmo II di Prussia"
}, {
  quote: "La birra si abbina all’idea del viaggio. In tutti i paesi c’è sempre una birra da scoprire, la birra locale è una costante universale, per l’intima soddisfazione di degustarla alla fine della giornata.",
  author: "Serge Joncour"
}, {
  quote: "La birra è tra le bevande più utili, tra i cibi più gustosi e tra i farmaci più piacevoli.",
  author: "Anonimo"
}, {
  quote: "Si può giudicare un popolo dal suo caffè, le sue sigarette, la sua birra.",
  author: "Michel Beaulieu"
}, {
  quote: "Filosofia e birra sono la stessa cosa, consumate, modificano tutte le percezioni che avevamo del mondo.",
  author: "Dominique-Joël Beaupré"
}, {
  quote: "Perché una birra e’ meglio di una donna? perché e’ sempre bagnata, perché dopo che te ne sei fatta una bionda te ne puoi fare subito una rossa, perché non si lamenta se te ne fai subito un’altra.",
  author: "Anonimo"
}, {
  quote: "La birra contiene sicuramente degli ormoni femminili… infatti quando si beve molta birra non si riesce a guidare la macchina e si dicono un sacco di cretinate… e si è costretti a pisciare seduti!",
  author: "Anonimo"
}, {
  quote: "Una birra forte, un tabacco profumato e una donna, questo è piacere.",
  author: "Johann Wolfgang Goethe"
}, {
  quote: "Conoscere i luoghi, vicino o lontani, non vale la pena, non è che teoria; saper dove meglio si spini la birra, è pratica vera, è geografia.",
  author: "Johann Wolfgang Goethe"
}, {
  quote: "La birra è la prova che Dio ci ama e vuole che siamo felici.",
  author: "Benjamin Franklin"
}, {
  quote: "Se uomo ama donna più di birra gelata davanti a tv con finale champions forse vero amore, ma non vero uomo.",
  author: "Vujadin Boskov"
}, {
  quote: "C’e’ gente che ha l’iPhone, chi ha l’iPad. Io ho l’iNeken.",
  author: "Anonimo"
}, {
  quote: "Vorrei il solito. Una birra, qualche sigaretta. Un ‘mi manchi’, un bacio o un ‘dov’eri?’. E poi vorrei un’altra birra. Che non si sa mai.",
  author: "Anonimo"
}, {
  quote: "Tutta questa birra e solo una bocca",
  author: "Anonimo"
}];
let quoteDict = {
  "eng": quoteListEng,
  "ita": quoteListIta
};
function languages() {
  return Object.keys(quoteDict);
}
function quotes(language) {
  let _languagesList = languages();
  if (language == undefined) {
    let _quoteList = [];
    for (let i = 0; i < _languagesList.length; i++) {
      _quoteList = _quoteList.concat(quoteDict[_languagesList[i]]);
    }
    return _quoteList;
  } else {
    let _quoteList = [];
    if (_languagesList.includes(language)) {
      _quoteList = quoteDict[language];
    }
    return _quoteList;
  }
}

},{}],3:[function(require,module,exports){
"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.VectorUtils = VectorUtils;
function VectorUtils() {
  function getRandomIndex(min, max) {
    return Math.floor(Math.random() * (max - min) + min);
  }
  function getAllIndexOf(array, value) {
    let indices = [];
    for (let i = 0; i < array.length; i++) {
      if (array[i] == value) {
        indices.push(i);
      }
    }
    return indices;
  }
  function getUnique(array) {
    return array.filter((v, i, a) => a.indexOf(v) === i);
  }
  function getVectorofRandomIndices(min, max, length, unique) {
    let indices = new Array(length);
    if (max - min < length) {
      unique = false;
    }
    if (unique) {
      for (let i = 0; i < length; i++) {
        let index = this.getRandomIndex(min, max);
        while (indices.indexOf(index) > 0) {
          index = this.getRandomIndex(min, max);
        }
        indices[i] = index;
      }
    } else {
      for (let i = 0; i < length; i++) {
        indices[i] = this.getRandomIndex(min, max);
      }
    }
    return indices;
  }
  return {
    getRandomIndex,
    getAllIndexOf,
    getUnique,
    getVectorofRandomIndices
  };
}

},{}]},{},[1])(1)
});
