function getQuote() {
  let randomQuote = beerq.BeerQuote().getRandomQuote();
  document.getElementById("quote").innerHTML = "<i>" + randomQuote.quote + "<br>[" + randomQuote.author + "]</i>";
}

setInterval(getQuote, 10000); /*Call it here*/
getQuote();