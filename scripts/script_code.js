const success = '<i class="fa-solid fa-check" style="color:#28a745;"></i>';
function copierCode(id, bouton) {
const code = document.getElementById(id).innerText;
navigator.clipboard.writeText(code).then(() => {
const oldIcon = bouton.innerHTML;
bouton.innerHTML = success;
bouton.disabled = true;

setTimeout(() => {
  bouton.innerHTML = oldIcon;
  bouton.disabled = false;
}, 1500);
});
}

function telechargerCode(id, nomFichier, typeMime, bouton) {
  const code = document.getElementById(id).innerText;
  const blob = new Blob([code], { type: typeMime });
  const lien = document.createElement('a');
  lien.href = URL.createObjectURL(blob);
  lien.download = nomFichier;
  lien.click();

  const oldIcon = bouton.innerHTML;
  bouton.innerHTML = success;
  bouton.disabled = true;

  setTimeout(() => {
    bouton.innerHTML = oldIcon;
    bouton.disabled = false;
  }, 1500);
}