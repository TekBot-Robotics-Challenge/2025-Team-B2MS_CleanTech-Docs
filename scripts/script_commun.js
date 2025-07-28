// Menu burger responsive
document.getElementById("sidebarToggle").addEventListener("click", () => {
document.querySelector(".sidebar").classList.toggle("open");
});

// Gérer activation des domaines
document.querySelectorAll(".tab-button").forEach(button => {
button.addEventListener("click", e => {
document.querySelectorAll(".tab-button").forEach(btn => btn.classList.remove("active"));
e.currentTarget.classList.add("active");

// Afficher le contenu lié
document.querySelectorAll(".tab-content").forEach(tc => tc.classList.remove("active"));
const target = e.currentTarget.getAttribute("data-target");
if (target) document.getElementById(target).classList.add("active");
});
});

// Sous-onglets
document.querySelectorAll(".subtab-button").forEach(button => {
button.addEventListener("click", e => {
const parent = e.currentTarget.closest(".tab-content");
parent.querySelectorAll(".subtab-button").forEach(btn => btn.classList.remove("active"));
e.currentTarget.classList.add("active");

parent.querySelectorAll(".subtab-content").forEach(content => content.classList.remove("active"));
const target = e.currentTarget.getAttribute("data-target");
parent.querySelector("#" + target).classList.add("active");
});
});

// script_commun.js
document.getElementById("sidebarToggle").addEventListener("click", () => {
  document.querySelector(".sidebar").classList.toggle("open");
});


// Gestion activation des projets (subtab-button)
document.querySelectorAll(".subtab-button").forEach(button => {
  button.addEventListener("click", e => {
    // Enlever active sur tous les boutons
    document.querySelectorAll(".subtab-button").forEach(btn => btn.classList.remove("active"));
    e.currentTarget.classList.add("active");

    // Afficher le contenu lié
    const parent = e.currentTarget.closest(".nav-section");
    parent.querySelectorAll(".subtab-content").forEach(tc => tc.classList.remove("active"));
    const target = e.currentTarget.getAttribute("data-target");
    if (target) document.getElementById(target).classList.add("active");

    // Afficher la sous-navigation liée au projet actif uniquement
    parent.querySelectorAll(".project-subnav").forEach(nav => nav.classList.remove("active"));
    const subnavId = "subnav-" + target;
    const activeSubnav = document.getElementById(subnavId);
    if (activeSubnav) activeSubnav.classList.add("active");
  });
});


window.addEventListener("scroll", () => {
  // Parcourt chaque projet
  document.querySelectorAll(".subtab-button").forEach(subtab => {
    const target = subtab.getAttribute("data-target");

    // Récupérer toutes les sections de ce projet
    const sections = document.querySelectorAll(`[id^="1-${target}"], [id^="2-${target}"], [id^="3-${target}"], [id^="4-${target}"], [id^="5-${target}"], [id^="6-${target}"], [id^="7-${target}"], [id^="8-${target}"]`);
    let currentSectionId = null;

    sections.forEach(section => {
      const rect = section.getBoundingClientRect();
      if (rect.top >= 0 && rect.top <= window.innerHeight / 2) {
        currentSectionId = section.id;
      }
    });

    // Activer la sous-nav correspondante
    if (currentSectionId) {
      // Active le bon projet (subtab-button)
      document.querySelectorAll(".subtab-button").forEach(btn => btn.classList.remove("active"));
      subtab.classList.add("active");

      // Activer la bonne project-subnav
      document.querySelectorAll(".project-subnav").forEach(nav => nav.classList.remove("active"));
      const subnav = document.getElementById(`subnav-${target}`);
      if (subnav) subnav.classList.add("active");

      // Activer le bon lien dans la sous-nav
      subnav.querySelectorAll("a").forEach(link => link.classList.remove("active"));
      const activeLink = subnav.querySelector(`a[href="#${currentSectionId}"]`);
      if (activeLink) activeLink.classList.add("active");
    }
  });
});

// Scroll fluide vers la section liée lors du clic sur un lien
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
  anchor.addEventListener("click", function (e) {
    const targetId = this.getAttribute("href").substring(1);
    const targetElement = document.getElementById(targetId);

    if (targetElement) {
      e.preventDefault(); // Empêche le saut instantané
      targetElement.scrollIntoView({ behavior: "smooth", block: "start" });
    }
  });
});
