function getQuote() {
  let randomQuote = beerq.BeerQuote().getRandomQuote();
  document.getElementById("quote").innerHTML = "<i>" + randomQuote.quote + "</i><br>[" + randomQuote.author + "]";
}

setInterval(getQuote, 10000); /*Call it here*/
getQuote();